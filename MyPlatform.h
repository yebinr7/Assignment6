// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlatform.generated.h"

// 로그 YB 로그카테고리
DECLARE_LOG_CATEGORY_EXTERN(YB, Warning, All);

UCLASS()
class ASSIGNMENT6_API AMyPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;







protected:
	// 언리얼에서 멤버변수는 파스칼! 첫글자 대문자 
	// 루트 컴포넌트를 나타내는 Scene Component 포인터로 해야 가비지컬렉터 충돌안남?


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	
	// Static Mesh Component 포인터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Properties")
	//초기위치 비긴플레이할때 얻어옴 
	FVector InitLocation;

	
};
