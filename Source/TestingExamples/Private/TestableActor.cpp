// Fill out your copyright notice in the Description page of Project Settings.


#include "TestableActor.h"
#include "TestableComponent.h"


ATestableActor::ATestableActor()
{
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));
	
	ChildComponent = CreateDefaultSubobject<UTestableComponent>("Child");
	ChildComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void ATestableActor::PerformAction()
{
	ChildComponent->CallMeMaybe();
}


