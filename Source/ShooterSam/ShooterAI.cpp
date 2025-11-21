#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterSamCharacter.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
		if (PlayerPawn)
		{
			if(LineOfSightTo(PlayerPawn))
			{
				SetFocus(PlayerPawn);
				MoveToActor(PlayerPawn, 200.0f);
			}
			else
			{
				ClearFocus(EAIFocusPriority::Gameplay);
				StopMovement();
			}
		}	
	*/
}

void AShooterAI::StartBehaviorTree(AShooterSamCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<AShooterSamCharacter>(GetPawn());

		if (Player)
		{
			PlayerCharacter = Player;
		}

		RunBehaviorTree(EnemyAIBehaviorTree);
		
		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		if (MyBlackboard && PlayerCharacter && MyCharacter )
		{
			MyBlackboard->SetValueAsVector("StartLocation", MyCharacter->GetActorLocation());
		}
	}
}
