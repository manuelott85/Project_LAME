// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LAME_AIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_LAME_API ALAME_AIController : public AAIController
{
	GENERATED_BODY()

public:
	ALAME_AIController();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FGenericTeamId TeamID = 2;

public:
	FGenericTeamId GetGenericTeamId() const override;
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);

protected:
	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;
};
