// Fill out your copyright notice in the Description page of Project Settings.


#include "YJSpawnVolume.h"

#if WITH_EDITOR
#include "DrawDebugHelpers.h"
#endif

AYJSpawnVolume::AYJSpawnVolume()
	: m_SpawnInterval(3.0f)
	, m_SpawnRange(500.0f)
{
	PrimaryActorTick.bCanEverTick = false;
}

void AYJSpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (World == nullptr || World->IsValidLowLevel() == false)
	{
		return;
	}

#if WITH_EDITOR
	//DrawDebugSphere(World, GetActorLocation(), m_SpawnRange, 16, FColor(0, 0, 0), true, -1, 2);
#endif

	// Ŭ���̾�Ʈ�� �ƴ� ��Ʈ��ũ ȯ�濡���� ����
	if (GetNetMode() != ENetMode::NM_Client)
	{
		FTimerDelegate SpawnTimerDelegate = FTimerDelegate::CreateUObject(this, &AYJSpawnVolume::SpawnActor);
		World->GetTimerManager().SetTimer(m_SpawnTimerHandle, SpawnTimerDelegate, m_SpawnInterval, true);
	}
}

void AYJSpawnVolume::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UWorld* World = GetWorld();
	if (World == nullptr || World->IsValidLowLevel() == false)
	{
		return;
	}

	if (World->GetTimerManager().IsTimerActive(m_SpawnTimerHandle) == true)
	{
		World->GetTimerManager().ClearTimer(m_SpawnTimerHandle);
	}
}

void AYJSpawnVolume::SpawnActor()
{
	if (m_SpawnClasses.Num() == 0)
	{
		return;
	}

	const FVector SpawnLocation = GetRandomLocation();
	const FRotator SpawnRotation = GetRandomRotation();
	const int32 RandIdx = FMath::RandRange(0, m_SpawnClasses.Num() - 1);
	FActorSpawnParameters SpawnParam;
	SpawnParam.Owner = this;

	UWorld* World = GetWorld();
	if (World == nullptr || World->IsValidLowLevel() == false)
	{
		return;
	}
	
	AActor* SpawnActor = World->SpawnActor<AActor>(m_SpawnClasses[RandIdx], SpawnLocation, SpawnRotation, SpawnParam);
}

const FVector AYJSpawnVolume::GetRandomLocation()
{
	const float X = FMath::RandRange(-m_SpawnRange, m_SpawnRange);
	const float Y = FMath::RandRange(-m_SpawnRange, m_SpawnRange);
	const float Z = 0.0f;

	FVector RandomLocation = FVector(X, Y, Z);
	RandomLocation = RandomLocation.GetClampedToSize2D(0, m_SpawnRange);

	// ���� ��ǥ�� ���� ��ġ�� ���� ������ ��� ��ǥ�� ��ȯ
	return GetTransform().TransformPosition(RandomLocation);
}

const FRotator AYJSpawnVolume::GetRandomRotation()
{
	const int32 AngleRange = 180;

	// Y�� ���� ȸ��
	const float Pitch = 0.0f;
	// Z�� ���� ȸ��
	const float Yaw = FMath::RandRange(-AngleRange, AngleRange);
	// X�� ���� ȸ��
	const float Roll = 0.0f;

	return FRotator(Pitch, Yaw, Roll);
}