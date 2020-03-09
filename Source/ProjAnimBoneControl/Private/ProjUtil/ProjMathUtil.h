#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProjMathUtil.generated.h"

UCLASS(Category="Util|Math")
class UProjMathUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/** 
	 * Computes rotation to apply to the X axis to aim at the given target
	 */
	UFUNCTION(BlueprintCallable, Category="Math|Util")
	static FRotator ComputeXAxisAimRotation(FVector TargetLocation);
	
};

// ~ RightHere_UProjMathUtil Begin


// Adhoc impl lines (WARNING! move to .cpp file, otherwise will fail to compile!)
// ~ RightHere_UProjMathUtil End

