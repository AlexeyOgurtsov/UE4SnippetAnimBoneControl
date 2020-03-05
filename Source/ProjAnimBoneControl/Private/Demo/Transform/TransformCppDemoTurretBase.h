#pragma once

#include "GameFramework/Actor.h"
#include "TransformCppDemoTurretBase.generated.h"

class UTransformCppDemoAnimInstanceBase;
class USkeletalMeshComponent;

UCLASS()
class ATransformCppDemoTurretBase : public AActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category=Anim)
	void IncreaseTurretYaw();

	UFUNCTION(BlueprintCallable, Category=Anim)
	void DecreaseTurretYaw();

	UFUNCTION(BlueprintCallable, Category=Anim)
	void IncreaseGunPitch();

	UFUNCTION(BlueprintCallable, Category=Anim)
	void DecreaseGunPitch();

	/** GetMyAnimInst*/
	UFUNCTION(BlueprintPure, Category=Anim)
	UTransformCppDemoAnimInstanceBase* GetMyAnimInstance() const
	{
		return MyAnimInstance;
	}

	/** GetMySkeletalMeshComponent*/
	UFUNCTION(BlueprintPure, Category=Anim)
	USkeletalMeshComponent* GetMySkeletalMeshComponent() const
	{
		return MySkeletalMeshComponent;
	}
	
protected:
	virtual void BeginPlay() override;
	
private:
	void InitializeHelperLinkVariables();
	void LinkToMyAnimInstance();


	/** MySkeletalMeshComponent*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(AllowPrivateAccess=true))
	USkeletalMeshComponent* MySkeletalMeshComponent = nullptr;
	
	/** MyAnimInst*/
	UPROPERTY(BlueprintReadOnly, Meta=(AllowPrivateAccess=true))
	UTransformCppDemoAnimInstanceBase* MyAnimInstance = nullptr;
};
