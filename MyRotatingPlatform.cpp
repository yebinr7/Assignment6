// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRotatingPlatform.h"

AMyRotatingPlatform::AMyRotatingPlatform()
	:RotationSpeed(0.0f)
{
	UE_LOG(YB, Error, TEXT("로테이션플랫폼 불림!!"));



}

void AMyRotatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//비긴플레이 됐을때  실행됐을때 초기 위치 설정 
	//SetActorLocation(FVector(300.f, 200.0f, 250.0f));


}

void AMyRotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//움직이는 함수 사용 
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		//Y Z X 축 피치야랄 
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}


