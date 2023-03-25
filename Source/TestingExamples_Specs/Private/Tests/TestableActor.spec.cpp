#if WITH_AUTOMATION_TESTS


#include "EngineUtils.h"
#include "TestableComponent.h"
#include "Misc/AutomationTest.h"
#include "TestingExamples_Specs/Private/Mocks/MockTestableComponent.h"

#define protected public
#include "TestingExamples/Public/TestableActor.h"
#undef protected

BEGIN_DEFINE_SPEC(FTestableActor_Spec, TEXT("TestingExamples.TestableActor"), EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority)
	TObjectPtr<UWorld> World = nullptr;
	TObjectPtr<UMockTestableComponent> MockChildComp = nullptr;
	TObjectPtr<ATestableActor> SUT;
END_DEFINE_SPEC(FTestableActor_Spec)

void FTestableActor_Spec::Define()
{
	BeforeEach([this]
	{
		World = UWorld::CreateWorld(EWorldType::Game, false);
		check(World);
		
		FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
		WorldContext.SetCurrentWorld(World);
		World->InitializeActorsForPlay(FURL());
		World->BeginPlay();
		
		SUT = World->SpawnActor<ATestableActor>();
	});

	AfterEach([this]
	{
		World->DestroyWorld(false);
	});

	Describe("When instantiating", [this]
	{
		It("should set Life to 100", [this]
		{
			TestEqual("Life equals 100", SUT->Life, 100);
		});

		It("Should create a child component", [this]
		{
			TArray<UActorComponent*> OutComponents;
			SUT->GetComponents(UTestableComponent::StaticClass(), OutComponents);

			TestFalse("Child Testable Components Exist", OutComponents.IsEmpty());
		});
	});

	Describe("When performing an action", [this]
	{
		BeforeEach([this]
		{
			MockChildComp = NewObject<UMockTestableComponent>();
			SUT->ChildComponent = MockChildComp;
			
			EXPECT_CALL(*MockChildComp.Get(), CallMeMaybe())
					.Times(1);
			
			SUT->PerformAction();
		});
		
		It("Should call CallMeMaybe on the child component", [this]
		{
			TestTrue("Verifying Json RPC Expectations", testing::Mock::VerifyAndClearExpectations(MockChildComp));
		});
	});
}

#endif

