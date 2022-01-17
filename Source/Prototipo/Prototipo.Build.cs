// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Prototipo : ModuleRules
{
	public Prototipo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks", "UMG" });
	}
}
