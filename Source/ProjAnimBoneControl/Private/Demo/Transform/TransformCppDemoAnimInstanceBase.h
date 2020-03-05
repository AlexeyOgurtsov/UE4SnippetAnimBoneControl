#pragma once

#include "Animation/AnimInstance.h"
#include "TransformCppDemoAnimInstanceBase.generated.h"

UCLASS()
class UTransformCppDemoAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:

	// WARNING!!! Never use UFUNCTION to access the variable inside the animation state machine
	// This is a thread safety issue ( message: node XXXXXXX uses potentially unthread-safe call)!!!

	/** TurretYaw*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta=(AllowPrivateAccess=true))
	float TurretYaw = 0.0F;

	/** GunPitch*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta=(AllowPrivateAccess=true))
	float GunPitch;
};
