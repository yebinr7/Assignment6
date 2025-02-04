// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlatform.h"

//내가 만든 로그카테고리 정의하기 헤더에서 선언한거 구현
DEFINE_LOG_CATEGORY(YB);


// Sets default values
AMyPlatform::AMyPlatform()
{
	//부모가 생성됐다는거 알리기
	UE_LOG(YB, Error, TEXT("부모플랫폼 불림!!"));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	/* ::CreateDefaultSubobject
	USceneComponent 타입의 새 객체를 생성함.
	이 함수는 언리얼 엔진의 UObject 시스템이 관리하는 
	서브 오브젝트를 생성할 때 사용됨.
	보통 AActor 또는 UObject 기반 클래스의 생성자에서만 사용 가능.
	*/
	SceneRoot = 
		CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);


	//staticMesh Component 생성 + SceneComponent(SceneRoot)에 장착
	//SceneRoot의 하위 컴포넌트로 동작하고, SceneRoot의 트랜스폼 변화에 따라같이 움직여짐 
	StaticMeshComp = 
		CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

}

// Called when the game starts or when spawned
void AMyPlatform::BeginPlay()
{
	Super::BeginPlay();
	InitLocation = GetActorLocation();
}

// Called every frame
void AMyPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

