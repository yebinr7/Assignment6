// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlatform.h"
#include "MyMovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT6_API AMyMovingPlatform : public AMyPlatform
{
	GENERATED_BODY()

	AMyMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//속도 조절 함수

	//속도 얻어오는 함수 

protected:

	UFUNCTION(BlueprintCallable, Category = "MovingPlatform|Actions")
	void MoveToTarget(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "MovingPlatform|Actions")
	void Trip(float DeltaTime);


	//인스턴스객체에서만 수정가능, 블루프린트에서 수정가능 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Properties")
	float MoveSpeed;
	
	
	//타겟위치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Properties")
	FVector TargetLocation;
};
