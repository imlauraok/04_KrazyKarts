// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.generated.h"

USTRUCT()
struct FGoKartMove
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	float Throttle;
	
	UPROPERTY()
	float SteeringThrow;

	UPROPERTY()
	float DeltaTime;
	
	UPROPERTY()
	float Time;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KRAZYKARTS_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SimulateMove(const FGoKartMove& Move);


	FVector GetVelocity() { return Velocity; }

	void SetVelocity(FVector Val) { Velocity = Val; }
	
	void SetThrottle(float Val) { Throttle = Val; }
	
	void SetSteeringThrow(float Val) { SteeringThrow = Val; }

	FGoKartMove GetLastMove() { return LastMove; }

private:
	FGoKartMove CreateMove(float DeltaTime);

	FVector GetAirResistance();

	FVector GetRollingResistance();

	void ApplyRotation(float DeltaTime, float SteeringThrow);

	void UpdateLocationFromVelocity(float DeltaTime);

	// The mass of the car in kg
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	// The force applied in newtons to the car when the throttle is at maximum value
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	// The minimum radius of the car turning circle at full lock in meters
	UPROPERTY(EditAnywhere)
	float MinTurningRadius = 10;

	// Amount of drag in kilograms per meter
	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16;

	// Amount of rolling resistance
	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015;

	FVector Velocity;

	float Throttle;
	float SteeringThrow;

	FGoKartMove LastMove;
};
