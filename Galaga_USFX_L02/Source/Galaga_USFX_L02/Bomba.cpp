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
	

    FTimerHandle BombaDestruida;
    GetWorld()->GetTimerManager().SetTimer(BombaDestruida, this, &ABomba::DestruirBomba, 5.0f, true);

  
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    MoverBomba(DeltaTime);
}

void ABomba::MoverBomba(float DeltaTime)
{
    // Mover la bomba hacia abajo en el eje Z
    FVector NewLocation = GetActorLocation();
    NewLocation.Z -= VelocidadBomba * DeltaTime;
    SetActorLocation(NewLocation);

    if (NewLocation.Z <= 0.0f)
    {
        DestruirBomba();
    }
}

void ABomba::DestruirBomba()
{
    if (ExplosionEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    }
   
    TArray<AActor*> OverlappingActors;
    GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (Actor && Actor != this && Actor->ActorHasTag("Enemy"))
        {
            Actor->TakeDamage(CantidadDanio, FDamageEvent(), nullptr, this);
        }
    }

    Destroy();
}

void ABomba::NotificarColision(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, OtherActor, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

    // Verificar si la bomba ha colisionado con el suelo u otro actor
    if (OtherActor && OtherActor != this)
    {
        // Activar el efecto de explosión
        DestruirBomba();
    }
}



