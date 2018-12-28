// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_PlayerCharacter.h"

// Sets default values
ALAME_PlayerCharacter::ALAME_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Assign to Team 1
	TeamId = FGenericTeamId(0);
}

FGenericTeamId ALAME_PlayerCharacter::GetGenericTeamId() const
{
	return TeamId;
}

// Called when the game starts or when spawned
void ALAME_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALAME_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALAME_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

