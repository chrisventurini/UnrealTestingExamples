// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestableComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTINGEXAMPLES_API UTestableComponent : public USceneComponent 
{
	GENERATED_BODY()

public:
	virtual void CallMeMaybe();
};
