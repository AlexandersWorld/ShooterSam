#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.generated.h"


UCLASS()
class SHOOTERSAM_API AShooterAI : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;

	AShooterSamCharacter* PlayerCharacter;
	AShooterSamCharacter* MyCharacter;

	void StartBehaviorTree(AShooterSamCharacter* Player);
};
