// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestableComponent.h"
#include "ThirdParty/GoogleTest/include/gmock/gmock.h"

#include "MockTestableComponent.generated.h"

UCLASS()
class UMockTestableComponent : public UTestableComponent 
{
	GENERATED_BODY()

public:
	MOCK_METHOD(void, CallMeMaybe, (), (override));
};
