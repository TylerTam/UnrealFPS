// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health.generated.h"



//This is required to have any blueprint-able events. (NOTE: Delegates must start with "F" in their name)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeadEventTrigger);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSPROJECT_API UHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "MyCustomCategory")
	virtual void DamageMe(int p_damageAmount, bool& p_isDead);

	
	UPROPERTY(BlueprintAssignable, Category = "Custom")
		FOnDeadEventTrigger OnIDied;

public:
	UPROPERTY(EditAnywhere)
	int startingHealth;
	UPROPERTY(EditAnywhere)
	int currentHealth;
};
