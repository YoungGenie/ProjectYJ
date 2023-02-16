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
	// 랜덤으로 스폰
	void SpawnActor();

	// 랜덤 위치
	const FVector GetRandomLocation();

	// 랜덤 회전
	const FRotator GetRandomRotation();

private:
	// 스폰할 액터 클래스 목록
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> m_SpawnClasses;

	// 스폰 간격 (단위 : 초(s))
	UPROPERTY(EditAnywhere)
	float m_SpawnInterval;

	// 스폰 범위
	UPROPERTY(EditAnywhere)
	float m_SpawnRange;

	// 스폰 타이머 핸들
	FTimerHandle m_SpawnTimerHandle;
};
