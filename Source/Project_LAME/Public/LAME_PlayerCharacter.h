// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"

#include "LAME_PlayerCharacter.generated.h"

UCLASS()
class PROJECT_LAME_API ALAME_PlayerCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	bool activateDebugLogging = false;

public:
	// Sets default values for this character's properties
	ALAME_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Assigns Team Agent to given TeamID */
	void SetGenericTeamId(const FGenericTeamId& NewTeamID);

	/** Retrieve team identifier in form of FGenericTeamId */
	FGenericTeamId GetGenericTeamId() const;

	/** Retrieved owner attitude toward given Other object */
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const;

};
