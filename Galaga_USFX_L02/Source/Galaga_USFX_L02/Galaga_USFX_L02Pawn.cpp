// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L02Pawn.h"
#include "Galaga_USFX_L02Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Bomba.h"

const FName AGalaga_USFX_L02Pawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFX_L02Pawn::MoveRightBinding("MoveRight");
const FName AGalaga_USFX_L02Pawn::FireForwardBinding("FireForward");
const FName AGalaga_USFX_L02Pawn::FireRightBinding("FireRight");

AGalaga_USFX_L02Pawn::AGalaga_USFX_L02Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;





	// Otro código del constructor
	VelocidadMovimiento = 100.0f; // Configurar la velocidad de movimiento por defecto

}

void AGalaga_USFX_L02Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);



	// configuracion para las teclas
	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &AGalaga_USFX_L02Pawn::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &AGalaga_USFX_L02Pawn::MoveDown);
	PlayerInputComponent->BindAction("FireBomb", IE_Pressed, this, &AGalaga_USFX_L02Pawn::FireBomb);
	PlayerInputComponent->BindAction("DestroyBomb", IE_Pressed, this, &AGalaga_USFX_L02Pawn::DestroyBomb);


}

void AGalaga_USFX_L02Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AGalaga_USFX_L02Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				// spawn the projectile
				World->SpawnActor<AGalaga_USFX_L02Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L02Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalaga_USFX_L02Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AGalaga_USFX_L02Pawn::MoveUp()
{
	// Aumentar la altura en un incremento pequeño
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation.Z += VelocidadMovimiento;
	SetActorLocation(CurrentLocation);
}

void AGalaga_USFX_L02Pawn::MoveDown()
{
	// Disminuir la altura en un decremento pequeño
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation.Z -= VelocidadMovimiento;
	SetActorLocation(CurrentLocation);
}

void AGalaga_USFX_L02Pawn::DestroyBomb()
{
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::M))
	{
		TArray<AActor*> Bombas;

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABomba::StaticClass(), Bombas);

		if (Bombas.Num() > 0)
		{
			Bombas[0]->Destroy();
		}
	}
}


void AGalaga_USFX_L02Pawn::FireBomb()
{
	if (BombaClass)
	{
		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();
		GetWorld()->SpawnActor<ABomba>(BombaClass, SpawnLocation, SpawnRotation);
	}
}
