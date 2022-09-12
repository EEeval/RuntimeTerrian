// Fill out your copyright notice in the Description page of Project Settings.


#include "Triangulator.h"


#include "ProceduralMeshComponent.h"


ATriangulator::ATriangulator()
{
	
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Earth"),false);
}

void ATriangulator::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void ATriangulator::Init()
{
	Earth = NewObject<UEarth>();
	float Ratio = (1.f + sqrt(5.f)) / 2.f;
	float Scale = Earth->GetRadius() / FVector2D(Ratio,1.0f).Size();
	Ratio *= Scale;

	TArray<FVector> IcoVertices;
	//X Plane
	IcoVertices.Push(FVector(Ratio,0,-Scale));   //rf 0
	IcoVertices.Push(FVector(-Ratio,0,-Scale));  //lf 1
	IcoVertices.Push(FVector(Ratio,0,Scale));    //rb 2
	IcoVertices.Push(FVector(-Ratio,0,Scale));   //lb 3
	//Y Plane
	IcoVertices.Push(FVector(0,-Scale,Ratio));   //rf 4
	IcoVertices.Push(FVector(0,-Scale,-Ratio));  //lf 5
	IcoVertices.Push(FVector(0,Scale,Ratio));    //rb 6
	IcoVertices.Push(FVector(0,Scale,-Ratio));   //lb 7
	//Z Plane
	IcoVertices.Push(FVector(-Scale,Ratio,0));   //rf 8
	IcoVertices.Push(FVector(-Scale,-Ratio,0));  //lf 9
	IcoVertices.Push(FVector(Scale,Ratio,0));    //rb 10
	IcoVertices.Push(FVector(Scale,-Ratio,0));   //lb 11

	TArray<int32> IcoTriangles = {
		1,3,8,
		1,3,9,
		0,2,10,
		0,2,11,

		0,5,7,
		5,7,1,
		4,6,2,
		3,6,4,
		
		9,11,4,
		9,11,5,
		8,10,6,
		8,10,7,
		
		1,7,8,
		5,1,9,
		0,7,10,
		0,5,11,

		3,6,8,
		3,4,9,
		2,10,6,
		2,4,11
	};
	
	SetRootComponent(ProceduralMesh);

	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;
	ProceduralMesh->CreateMeshSection(
		0,
		IcoVertices,
		IcoTriangles,
		Normals,
		UVs,
		VertexColors,
		Tangents,
		false
		);
	//ProceduralMesh->SetMaterial
	
}

bool ATriangulator::Update()
{
	return true;
}

void ATriangulator::GenerateGeometry()
{
}
