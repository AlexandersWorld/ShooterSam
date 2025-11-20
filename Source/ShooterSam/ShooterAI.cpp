#include "ShooterAI.h"
#include "ShooterSamCharacter.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	isAlive = true;
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{
		SetFocus(PlayerPawn);

		MoveToActor(PlayerPawn, 200.0f);
	}
}
