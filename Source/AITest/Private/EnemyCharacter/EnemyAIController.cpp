// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter/EnemyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"


AEnemyAIController::AEnemyAIController()
{
	RepeatInterval = 3.f; 
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle,this,
		&AEnemyAIController::OnRepeatTimer,true);
}

void AEnemyAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void AEnemyAIController::OnRepeatTimer()
{
	auto CurrentPawn = GetPawn();
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (CurrentPawn == nullptr || NavSystem == nullptr)
	{
		return; 
	}
	FNavLocation NextLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 1000.f, NextLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this,NextLocation.Location);
		UE_LOG(LogTemp,Log, TEXT("Nav Location Updated - %s"), *NextLocation.Location.ToString());
	}
}


void AEnemyAIController::OnTargetDetected(AActor* Actor, FAIStimulus const stimulus)
{
}
