// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPawn.h"

#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#define print(color, text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, color, text)

// Sets default values
AAIPawn::AAIPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAIPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/** Assigns Team Agent to given TeamID */
void AAIPawn::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	IGenericTeamAgentInterface* currentInterface = Cast<IGenericTeamAgentInterface>(GetController());
	if (currentInterface)
		currentInterface->SetGenericTeamId(NewTeamID);
	else
		if (activateDebugLogging)
			print(FColor::Red, GetName() + " current Interface missing (SetGenericTeamId)!");

	if (activateDebugLogging)
		print(FColor::Green, GetName() + " sets his TeamID to: " + FString::FromInt(NewTeamID));
}

/** Retrieve team identifier in form of FGenericTeamId */
FGenericTeamId AAIPawn::GetGenericTeamId() const
{
	FGenericTeamId value = 255;

	IGenericTeamAgentInterface* currentInterface = Cast<IGenericTeamAgentInterface>(GetController());
	if (currentInterface)
		value = currentInterface->GetGenericTeamId();
	else
		if (activateDebugLogging)
			print(FColor::Red, GetName() + " current Interface missing (GetGenericTeamId)!");

	if (activateDebugLogging)
		print(FColor::Green, GetName() + " reports his GenericTeamID: " + FString::FromInt(value));

	return value;
}

/** Retrieved owner attitude toward given Other object */
ETeamAttitude::Type AAIPawn::GetTeamAttitudeTowards(const AActor& Other) const
{
	ETeamAttitude::Type value = ETeamAttitude::Hostile;

	IGenericTeamAgentInterface* currentInterface = Cast<IGenericTeamAgentInterface>(GetController());
	if (currentInterface)
		value = currentInterface->GetTeamAttitudeTowards(Other);
	else
		if (activateDebugLogging)
			print(FColor::Red, GetName() + " current Interface missing (GetTeamAttitudeTowards)!");

	if (activateDebugLogging)
		print(FColor::Green, "The attitude of " + GetName() + " towards " + Other.GetName() + " is: " + FString::FromInt(value));

	return value;
}