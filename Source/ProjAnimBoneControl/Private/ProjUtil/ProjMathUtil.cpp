#include "ProjMathUtil.h"
#include "Math/UnrealMathUtility.h"
#include "GenericPlatform/GenericPlatformMath.h"

FRotator UProjMathUtil::ComputeXAxisAimRotation(FVector TargetLocation)
{
	if(TargetLocation.IsNearlyZero()) return FRotator{};
	const FVector DirectionToLocation = TargetLocation.GetUnsafeNormal();

	// WARN!!! Pitch is always between (-90;90)
	const float SinPitch = DirectionToLocation.Z;
	const float PitchRads = FMath::FastAsin(SinPitch);
	const float PitchDegs = FMath::RadiansToDegrees(PitchRads);
	const float CosPitch = FMath::Cos(PitchRads);

	// Yaw is between -180; 180
	//const float SinYaw = - DirectionToLocation.Y / CosPitch;
	//const float YawDegs = FMath::RadiansToDegrees(FMath::FastAsin(SinYaw));
	const float YawRads = FGenericPlatformMath::Atan2(DirectionToLocation.Y, DirectionToLocation.X);
	const float YawDegs = FMath::RadiansToDegrees(YawRads);
	return FRotator { PitchDegs, YawDegs, 0 };
}
