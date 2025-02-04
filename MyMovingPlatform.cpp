// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMovingPlatform.h"

AMyMovingPlatform::AMyMovingPlatform()
	:MoveSpeed(0.0f), TargetLocation{0.0f,0.0f,0.0f}
{
	UE_LOG(YB, Error, TEXT("무빙플랫폼 불림!!"));



	//메쉬얻어서 설정하기
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset
	(TEXT(""));
	//방어코드
	if (MeshAsset.Succeeded())
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);



	//Material 얻어서 설정하기
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset
	(TEXT(""));
	//방어코드
	if (MaterialAsset.Succeeded())
		StaticMeshComp->SetMaterial(0/*몇번째슬롯에넣을것인지*/, MaterialAsset.Object);
}

void AMyMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//타겟으로 움직이는 로직 
	/*if (!FMath::IsNearlyZero(MoveSpeed))
		MoveToTarget(DeltaTime);*/

}

void AMyMovingPlatform::MoveToTarget(float DeltaTime)
{
	//1. 이동할 목표 설정 -> 블루프린트나, 에디터에 설정할수있게 만들어두기 
	//FVector TargetLocation{ 1000.0f,1000.0f,1000.0f };


	//2. 현재 위치 받아오기
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);

	//3. 매프레임 새로운 위치로 액터 위치 업데이트  
	SetActorLocation(NewLocation);
}

void AMyMovingPlatform::Trip(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
	SetActorLocation(NewLocation);

	// 거리 기반으로 도착 여부 체크 (정확한 비교 대신 작은 거리 차이 확인) 부동소수점이라서!
	if (FVector::Dist(GetActorLocation(), TargetLocation) < 100.0f)
	{
		//TargetLocation = InitLocation;
		Swap(TargetLocation, InitLocation);//왕복가능 
	}
}

