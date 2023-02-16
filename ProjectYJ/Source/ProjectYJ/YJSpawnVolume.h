// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YJSpawnVolume.generated.h"

UCLASS(Blueprintable)
class AYJSpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	AYJSpawnVolume();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	// �������� ����
	void SpawnActor();

	// ���� ��ġ
	const FVector GetRandomLocation();

	// ���� ȸ��
	const FRotator GetRandomRotation();

private:
	// ������ ���� Ŭ���� ���
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> m_SpawnClasses;

	// ���� ���� (���� : ��(s))
	UPROPERTY(EditAnywhere)
	float m_SpawnInterval;

	// ���� ����
	UPROPERTY(EditAnywhere)
	float m_SpawnRange;

	// ���� Ÿ�̸� �ڵ�
	FTimerHandle m_SpawnTimerHandle;
};
