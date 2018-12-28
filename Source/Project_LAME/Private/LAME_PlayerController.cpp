// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_PlayerController.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#define print(color, text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, color, text)

ALAME_PlayerController::ALAME_PlayerController()
{
	// Assign to Team 1
	//SetGenericTeamId(FGenericTeamId(1));

	FGenericTeamId::SetAttitudeSolver(&ALAME_PlayerController::GetAttitudeTowards);
}

FGenericTeamId ALAME_PlayerController::GetGenericTeamId() const
{
	print(FColor::Magenta, GetName() + ": Your Team ID is: " + FString::FromInt(TeamID.GetId()));
	return TeamID;
}

ETeamAttitude::Type ALAME_PlayerController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (const APawn* OtherCharacter = Cast<APawn>(&Other))
	{
		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherCharacter->GetController()))
		{
			//return Super::GetTeamAttitudeTowards(*OtherCharacter->GetController());
			print(FColor::Red, GetName() + ": Your attitude towards " + Other.GetName() + " is: ERROR");
			return ETeamAttitude::Hostile;
		}
		return GetAttitudeTowardsPlayer(Other);
	}

	print(FColor::Magenta, GetName() + ": Your attitude towards is: Neutral");
	return ETeamAttitude::Neutral;
}

ETeamAttitude::Type ALAME_PlayerController::GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB)
{
	if (TeamA == TeamB)
	{
		print(FColor::Magenta, "Static PlayerCtrl: Your attitude towards is: Friendly");
		return ETeamAttitude::Friendly;
	}
	else
	{
		print(FColor::Magenta, "Static PlayerCtrl: Your attitude towards is: Hostile");
		return ETeamAttitude::Hostile;
	}
}

ETeamAttitude::Type ALAME_PlayerController::GetAttitudeTowardsPlayer(const AActor& Other) const
{
	print(FColor::Magenta, GetName() + ": Your attitude towards the player is: Hostile");
	return ETeamAttitude::Hostile;
}