// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_PlayerController.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#define print(color, text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, color, text)

ALAME_PlayerController::ALAME_PlayerController()
{
	FGenericTeamId::SetAttitudeSolver(&ALAME_PlayerController::GetAttitudeTowards);
}

/** Assigns Team Agent to given TeamID */
void ALAME_PlayerController::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	//print(FColor::Cyan, GetName() + " sets a new TeamID to: " + FString::FromInt(NewTeamID.GetId()));
	TeamID = NewTeamID;
}

FGenericTeamId ALAME_PlayerController::GetGenericTeamId() const
{
	//print(FColor::Magenta, GetName() + ": Your Team ID is: " + FString::FromInt(TeamID.GetId()));
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

	//print(FColor::Magenta, GetName() + ": Your attitude towards " + Other.GetName() + " is: Neutral");
	return ETeamAttitude::Neutral;
}

ETeamAttitude::Type ALAME_PlayerController::GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB)
{
	if (TeamA == TeamB)
	{
		//print(FColor::Yellow, "Static AICtrl: The attitude of " + FString::FromInt(TeamA.GetId()) + " towards " + FString::FromInt(TeamB.GetId()) + " is: Friendly");
		return ETeamAttitude::Friendly;
	}
	else
	{
		//print(FColor::Yellow, "Static AICtrl: The attitude of " + FString::FromInt(TeamA.GetId()) + " towards " + FString::FromInt(TeamB.GetId()) + " is: Hostile");
		return ETeamAttitude::Hostile;
	}
}

ETeamAttitude::Type ALAME_PlayerController::GetAttitudeTowardsPlayer(const AActor& Other) const
{
	//print(FColor::Magenta, GetName() + ": Your attitude towards the player is: Hostile");
	return ETeamAttitude::Hostile;
}