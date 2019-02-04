// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "UFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_LAME_API UFunctionLibrary : public UObject
{
	GENERATED_BODY()
	
public:
	UFunctionLibrary();
	~UFunctionLibrary();

	static UAISenseConfig* GetPerceptionSenseConfig(AAIController* Controller, TSubclassOf<UAISense> SenseClass);

	UFUNCTION(BlueprintCallable, Category = "AI|Perception")
		static bool SetSightRange(AAIController* Controller, float SightRange);
};
