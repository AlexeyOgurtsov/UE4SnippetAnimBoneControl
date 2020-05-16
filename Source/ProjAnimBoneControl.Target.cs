// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjAnimBoneControlTarget : TargetRules
{
	public ProjAnimBoneControlTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		ExtraModuleNames.AddRange( new string[] { "ProjAnimBoneControl" } );

		bUseUnityBuild = false;
		bUsePCHFiles = false;
	}
}
