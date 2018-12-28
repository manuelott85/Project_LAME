// Fill out your copyright notice in the Description page of Project Settings.

#include "LAME_AIController.h"

ALAME_AIController::ALAME_AIController()
{
	// Assign to Team 1
	//SetGenericTeamId(FGenericTeamId(1));

	FGenericTeamId::SetAttitudeSolver(&ALAME_AIController::GetAttitudeTowards);
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
	return TeamA == TeamB ? ETeamAttitude::Friendly : ETeamAttitude::Hostile;
}

ETeamAttitude::Type ALAME_AIController::GetAttitudeTowardsPlayer(const AActor& Other) const
{
	return ETeamAttitude::Hostile;
}