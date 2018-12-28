// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_PlayerCharacter.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#define print(color, text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, color, text)

// Sets default values
ALAME_PlayerCharacter::ALAME_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

/** Assigns Team Agent to given TeamID */
void ALAME_PlayerCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	if (activateDebugLogging)
		print(FColor::Cyan, GetName() + " sets a new TeamID");
	Cast<IGenericTeamAgentInterface>(GetController())->SetGenericTeamId(NewTeamID);	// call the function in the controller
}

/** Retrieve team identifier in form of FGenericTeamId */
FGenericTeamId ALAME_PlayerCharacter::GetGenericTeamId() const
{
	if (activateDebugLogging)
		print(FColor::Cyan, GetName() + " wants to know the GenericTeamID");

	FGenericTeamId value = 255;

	AController* currentController = GetController();
	if (currentController)
	{
		IGenericTeamAgentInterface* currentInterface = Cast<IGenericTeamAgentInterface>(currentController);
		if (currentInterface)
			value = Cast<IGenericTeamAgentInterface>(GetController())->GetGenericTeamId();
	}
	return value;
}

/** Retrieved owner attitude toward given Other object */
ETeamAttitude::Type ALAME_PlayerCharacter::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (activateDebugLogging)
		print(FColor::Cyan, GetName() + " wants to know the attitude towards: " + Other.GetName());
	return Cast<IGenericTeamAgentInterface>(GetController())->GetTeamAttitudeTowards(Other);	// call the function in the controller
}