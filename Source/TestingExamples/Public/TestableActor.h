// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestableActor.generated.h"

UCLASS()
class TESTINGEXAMPLES_API ATestableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestableActor();
	
	virtual void PerformAction();
	
	UPROPERTY(BlueprintReadWrite)
	int Life = 100;
	
protected:	
	TObjectPtr<class UTestableComponent> ChildComponent;
};

