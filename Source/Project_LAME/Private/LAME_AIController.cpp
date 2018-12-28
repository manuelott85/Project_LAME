// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_AIController.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#define print(color, text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, color, text)

ALAME_AIController::ALAME_AIController()
{
	// Assign to Team 1
	//SetGenericTeamId(FGenericTeamId(1));

	FGenericTeamId::SetAttitudeSolver(&ALAME_AIController::GetAttitudeTowards);
}

FGenericTeamId ALAME_AIController::GetGenericTeamId() const
{
	print(FColor::Yellow, "Your Team ID is: " + FString::FromInt(TeamID.GetId()));
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
	return ETeamAttitude::Neutral;
}

ETeamAttitude::Type ALAME_AIController::GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB)
{
	if (TeamA == TeamB)
	{
		print(FColor::Yellow, "Your attitude towards is: Friendly");
		return ETeamAttitude::Friendly;
	}
	else
	{
		print(FColor::Yellow, "Your attitude towards is: Hostile");
		return ETeamAttitude::Hostile;
	}

	//return TeamA == TeamB ? ETeamAttitude::Friendly : ETeamAttitude::Hostile;
}

ETeamAttitude::Type ALAME_AIController::GetAttitudeTowardsPlayer(const AActor& Other) const
{
	print(FColor::Yellow, "Your attitude towards the player is: Hostile");
	return ETeamAttitude::Hostile;
}