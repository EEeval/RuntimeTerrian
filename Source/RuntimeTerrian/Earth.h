// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Earth.generated.h"

/**
 * 
 */
UCLASS()
class RUNTIMETERRIAN_API UEarth : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	float GetRadius() const{ return Radius; }
	
private:
	
	//Planet parameters
	UPROPERTY()
	float Radius = 6371.1f;
	UPROPERTY()
	float MaxHeight = 8.848f;
};
