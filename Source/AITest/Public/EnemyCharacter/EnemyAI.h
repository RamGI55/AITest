// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAI.generated.h"

class UAIPerceptionSystem; 
class UEnemyAIController; 
UCLASS()
class AITEST_API AEnemyAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	explicit AEnemyAI();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION() 
	void SetupPerceptionSystem(); 
	

public: 


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception", meta = (AllowPrivateAccess = "true"))
	class UAISenseConfig_Sight* SightPerception;
	
	
	
	
};



