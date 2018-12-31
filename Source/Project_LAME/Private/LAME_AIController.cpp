// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_AIController.h"
#include "Runtime/AIModule/Classes/Navigation/CrowdFollowingComponent.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#define print(color, text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, color, text)

//ALAME_AIController::ALAME_AIController()
ALAME_AIController::ALAME_AIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	// Assign to Team 1
	//SetGenericTeamId(FGenericTeamId(1));

	FGenericTeamId::SetAttitudeSolver(&ALAME_AIController::GetAttitudeTowards);
}

FGenericTeamId ALAME_AIController::GetGenericTeamId() const
{
	//print(FColor::Yellow, GetName() + ": Your Team ID is: " + FString::FromInt(TeamID.GetId()));
	return TeamID;
}

ETeamAttitude::Type ALAME_AIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (const APawn* OtherCharacter = Cast<APawn>(&Other))
	{
		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherCharacter->GetController()))
		{
			return Super::GetTeamAttitudeTowards(*OtherCharacter->GetController());
		}
		return GetAttitudeTowardsPlayer(Other);
	}

	//print(FColor::Yellow, GetName() + ": Your attitude towards is: Neutral");
	return ETeamAttitude::Neutral;
}

ETeamAttitude::Type ALAME_AIController::GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB)
{
	if (TeamA == TeamB)
	{
		//print(FColor::Yellow, "Static AICtrl: Your attitude towards is: Friendly");
		return ETeamAttitude::Friendly;
	}
	else
	{
		//print(FColor::Yellow, "Static AICtrl: Your attitude towards is: Hostile");
		return ETeamAttitude::Hostile;
	}
}

ETeamAttitude::Type ALAME_AIController::GetAttitudeTowardsPlayer(const AActor& Other) const
{
	//print(FColor::Yellow, GetName() + ": Your attitude towards the player is: Hostile");
	return ETeamAttitude::Hostile;
}