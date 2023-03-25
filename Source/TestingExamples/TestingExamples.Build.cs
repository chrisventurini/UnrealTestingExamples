// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestingExamples : ModuleRules
{
	public TestingExamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new []
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore"
		});
	}
}
