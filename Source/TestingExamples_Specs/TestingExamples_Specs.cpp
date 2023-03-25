#include "TestingExamples_Specs.h"

#include "gtest/gtest.h"

#define LOCTEXT_NAMESPACE "FTestingExamples_SpecsModule"

#if WITH_AUTOMATION_TESTS
// For GoogleTest Error Reporting
class TestHelpersFailureReporter : public testing::EmptyTestEventListener
{
	virtual void OnTestPartResult(const testing::TestPartResult& result) override
	{
		if (result.type() == testing::TestPartResult::kFatalFailure
				|| result.type() == testing::TestPartResult::kNonFatalFailure)
		{
			const auto Message = FString(result.message());
			UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
		}
	}
};
#endif
void FTestingExamples_SpecsModule::StartupModule()
{
#if WITH_AUTOMATION_TESTS
	// For GoogleTest Error Reporting
	testing::UnitTest::GetInstance()->listeners().Append(new TestHelpersFailureReporter);
#endif
}

void FTestingExamples_SpecsModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FTestingExamples_SpecsModule, TestingExamples_Specs)