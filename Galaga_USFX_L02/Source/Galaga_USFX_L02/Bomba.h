// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomba.generated.h"

UCLASS()
class GALAGA_USFX_L02_API ABomba : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BombaMesh; // Malla visual de la bomba


	UPROPERTY()
		float VelocidadBomba; // Velocidad de caída de la bomba

	
	
public:	
	// Sets default values for this actor's properties
	ABomba();
	void SetVelocidadBomba(float velocidadBomba) { VelocidadBomba = velocidadBomba; }
	UPROPERTY(EditAnywhere, Category = "Gameplay")
		float CantidadDanio = 10.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	void MoverBomba(float DeltaTime);
	void DestruirBomba();

};
