#include "TransformCppDemoTurretBase.h"
#include "TransformCppDemoAnimInstanceBase.h"
#include "Util/Core/LogUtilLib.h"

#include "Components/SkeletalMeshComponent.h"

// ~ Constants Begin
constexpr float TURRET_YAW_INCREMENT_DEGS = 3.0F;
constexpr float GUN_PITCH_INCREMENT_DEGS = 5.0F;
// ~ Constants End

void ATransformCppDemoTurretBase::IncreaseTurretYaw()
{
	M_LOGFUNC();
	if(MyAnimInstance == nullptr)
	{
		M_LOG_ERROR(TEXT("Skipping action - animation instance is NOT initialized"));
		return;
	}
	MyAnimInstance->TurretYaw += TURRET_YAW_INCREMENT_DEGS;
}

void ATransformCppDemoTurretBase::DecreaseTurretYaw()
{
	M_LOGFUNC();
	if(MyAnimInstance == nullptr)
	{
		M_LOG_ERROR(TEXT("Skipping action - animation instance is NOT initialized"));
		return;
	}

	MyAnimInstance->TurretYaw -= TURRET_YAW_INCREMENT_DEGS;
}

void ATransformCppDemoTurretBase::IncreaseGunPitch()
{
	M_LOGFUNC();
	if(MyAnimInstance == nullptr)
	{
		M_LOG_ERROR(TEXT("Skipping action - animation instance is NOT initialized"));
		return;
	}

	MyAnimInstance->GunPitch += GUN_PITCH_INCREMENT_DEGS;
}

void ATransformCppDemoTurretBase::DecreaseGunPitch()
{
	M_LOGFUNC();
	if(MyAnimInstance == nullptr)
	{
		M_LOG_ERROR(TEXT("Skipping action - animation instance is NOT initialized"));
		return;
	}

	MyAnimInstance->GunPitch -= GUN_PITCH_INCREMENT_DEGS;
}

void ATransformCppDemoTurretBase::BeginPlay()
{
	M_LOGFUNC();
	Super::BeginPlay();
	InitializeHelperLinkVariables();
}

void ATransformCppDemoTurretBase::InitializeHelperLinkVariables()
{
	M_LOGFUNC();
	MySkeletalMeshComponent = FindComponentByClass<USkeletalMeshComponent>();
	if( MySkeletalMeshComponent == nullptr )
	{
		M_LOG_ERROR(TEXT("Unable to find skeletal mesh component"));
		return;
	}
	LinkToMyAnimInstance();
}

void ATransformCppDemoTurretBase::LinkToMyAnimInstance()
{
	M_LOGFUNC();
	checkf(MySkeletalMeshComponent, TEXT("Skeletal mesh component link must be initialized with a NON-null value when calling \"%s\""), TEXT(__FUNCTION__));
	
	if(MySkeletalMeshComponent->GetAnimationMode() != EAnimationMode::Type::AnimationBlueprint)
	{
		M_LOG_ERROR(TEXT("Skeletal mesh animation is NOT handled by animation blueprint"));
		return;
	}

	if(UAnimInstance* AnimInst = MySkeletalMeshComponent->GetAnimInstance())
	{
		MyAnimInstance = Cast<UTransformCppDemoAnimInstanceBase>(AnimInst);
		if(MyAnimInstance == nullptr)
		{
			M_LOG_ERROR(TEXT("Unable to initialize link to animation instance of the skeletal mesh"));
			return;
		}
	}
	else
	{
		M_LOG_ERROR(TEXT("Animation instance pointer of the skeletal mesh is nullptr"));
		return;
	}
}

