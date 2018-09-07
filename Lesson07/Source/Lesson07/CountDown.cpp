// Fill out your copyright notice in the Description page of Project Settings.

#include "CountDown.h"

// Sets default values
ACountDown::ACountDown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CountDownTime = 3;
	CountDownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountDownText"));
	CountDownText->SetHorizontalAlignment(EHTA_Center);
	CountDownText->SetWorldSize(150.0f);
	RootComponent = CountDownText;

}

// Called when the game starts or when spawned
void ACountDown::BeginPlay()
{
	Super::BeginPlay();
	UpdateCountTimeDisplay();
	//	Handle
	//	Banben
	//	方法
	//	间隔时间
	//	是否循环
	//	第一次执行提前时间
	GetWorldTimerManager().SetTimer(CountDownTimeHandle, this, &ACountDown::AdvanceTimer, 2.0f, true, -2);
}

// Called every frame
void ACountDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountDown::AdvanceTimer()
{
	--CountDownTime;
	UpdateCountTimeDisplay();
	if (CountDownTime<0)
	{
		GetWorldTimerManager().ClearTimer(CountDownTimeHandle);
		CountDownFinished();
	}
}

void ACountDown::UpdateCountTimeDisplay()
{
	CountDownText->SetText(FString::FromInt(FMath::Max(CountDownTime, 0)));
}

void ACountDown::CountDownFinished_Implementation()
{
	CountDownText->SetText(TEXT("GO!"));
}

