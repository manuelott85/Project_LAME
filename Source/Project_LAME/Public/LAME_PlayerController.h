// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"

#include "LAME_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_LAME_API ALAME_PlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ALAME_PlayerController();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FGenericTeamId TeamID = 1;

public:
	FGenericTeamId GetGenericTeamId() const override;
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);

protected:
	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;
};
