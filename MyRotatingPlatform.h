// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlatform.h"
#include "MyRotatingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT6_API AMyRotatingPlatform : public AMyPlatform
{
	GENERATED_BODY()

	AMyRotatingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//인스턴스객체에서만 수정가능, 블루프린트에서 수정가능 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingPlatform|Properties")
	float RotationSpeed;


};
