// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectYJ : ModuleRules
{
	public ProjectYJ(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore", 
				"HeadMountedDisplay", 
				"RawMesh", 



				"VertexAnimToolset", 
				"VertexAnimToolsetEditor" 
			}
			);

		PublicIncludePaths.AddRange(new string[] { ModuleDirectory, });

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"UnrealEd",
				"RenderCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
	}
}
