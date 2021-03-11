// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class EditorUtilities : ModuleRules
{
	public EditorUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateIncludePaths.AddRange(new string[] { System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "Source\\Editor\\Blutility\\Private" });
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "TestingGround" });

		PublicIncludePaths.AddRange(
			new string[] 
			{ 
				"EditorUtilities" 
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] 
			{ 
				"Blutility",
				"UnrealEd"
			 });
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
