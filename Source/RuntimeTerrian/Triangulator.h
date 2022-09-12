// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Earth.h"
#include "Triangulator.generated.h"

enum TriNext
{
	CULL,
	LEAF,
	SPLIT,
	SPLITCULL
};

/*USTRUCT()
struct FTri
{
	GENERATED_BODY()

	FTri(){}
	FTri(FVector A, FVector B, FVector C, FTri* Parent, short Level)
		:a(A), b(B), c(C), parent(Parent), level(Level)
	{
	}

	FTri* parent = nullptr;

	FTri* c1 = nullptr;
	FTri* c2 = nullptr;
	FTri* c3 = nullptr;
	FTri* c4 = nullptr;

	TriNext state;

	short level;

	FVector a;
	FVector b;
	FVector c;
};*/

/**
 * 
 */
UCLASS()
class RUNTIMETERRIAN_API ATriangulator : public AActor
{

	GENERATED_BODY()
public:
	ATriangulator();
		

	UFUNCTION()
	virtual void BeginPlay() override;
	UFUNCTION()
	void Init();
	UFUNCTION()
	bool Update();
	UFUNCTION()
	void GenerateGeometry();
	
private:
	UPROPERTY()
	UEarth* Earth;

	UPROPERTY()
	class UProceduralMeshComponent* ProceduralMesh;
	
};

























