// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
class UAISenseConfig_Sight; 
UCLASS()
class AITEST_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	

protected:

private:
	UFUNCTION() 
	void OnRepeatTimer();

	UFUNCTION()
	void SetUpPerceptionSystem();

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const stimulus); 

private:
	FTimerHandle RepeatTimerHandle;
	float RepeatInterval;
	
};
