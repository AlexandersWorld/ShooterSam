// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.h"

AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}

void AShooterSamGameMode::BeginPlay()
{
	Super::BeginPlay();

	AShooterSamCharacter* Player = Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	TArray<AActor*> FoundShooters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), FoundShooters);

	for (AActor* Shooter : FoundShooters)
	{
		if (AShooterAI* ShooterAI = Cast<AShooterAI>(Shooter))
		{
			ShooterAI->StartBehaviorTree(Player);
		}
	}
}
