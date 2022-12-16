// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"

// Sets default values for this component's properties
UHealth::UHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = startingHealth;
	// ...
	
}


// Called every frame
void UHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealth::DamageMe(int p_damageAmount, bool& p_isDead) {
	if (currentHealth <= 0) {
		return;
	}
	currentHealth -= p_damageAmount;
	if (currentHealth <= 0) {
		currentHealth = 0;
		p_isDead = true;
		OnIDied.Broadcast();
	}
	p_isDead = false;
}




