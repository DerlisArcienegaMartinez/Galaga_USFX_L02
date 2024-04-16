// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Crear y configurar la malla visual de la bomba
    BombaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombaMesh"));
    RootComponent = BombaMesh;

    UProjectileMovementComponent* ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->UpdatedComponent = BombaMesh;
    ProjectileMovement->InitialSpeed = 0.0f;
    ProjectileMovement->ProjectileGravityScale = 0.0f;

    // Cargar una malla estática para la bomba (debes asignar una malla en el editor)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BombaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
    if (BombaMeshAsset.Succeeded())
    {
        BombaMesh->SetStaticMesh(BombaMeshAsset.Object);
    }
    

    VelocidadBomba = 500.0f; // Velocidad inicial de caída
}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	
  
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    MoverBomba(DeltaTime);
}

void ABomba::MoverBomba(float DeltaTime)
{

    FVector Start = GetActorLocation();
    FVector End = Start + FVector(0.0f, 0.0f, -1.0f);

    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.bTraceComplex = true;

    if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
    {
        SetActorLocation(HitResult.ImpactPoint + FVector(0.0f, 0.0f, BombaMesh->GetStaticMesh()->GetBounds().BoxExtent.Z));
    
        VelocidadBomba = 0.0f;
    }
    else
    {
        // Mover la bomba hacia abajo en el eje Z
        FVector NewLocation = GetActorLocation();
        NewLocation.Z -= VelocidadBomba * DeltaTime;
        SetActorLocation(NewLocation);

        if (NewLocation.Z <= 200.0f)
        {
            VelocidadBomba = 0.0f;
        }
    }
}




