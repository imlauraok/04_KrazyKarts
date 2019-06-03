// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector GetAirResistance();

	FVector GetRollingResistance();

	void ApplyRotation(float DeltaTime);

	void UpdateLocationFromVelocity(float DeltaTime);

	// The mass of the car in kg
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	// The force applied in newtons to the car when the throttle is at maximum value
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	// The maximum number of degrees rotated per second
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 90;

	// Amount of drag in kilograms per meter
	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16;

	// Amount of rolling resistance
	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015;

	void MoveForward(float Value);

	void MoveRight(float Value);

	FVector Velocity;

	float Throttle;

	float SteeringThrow;
};
