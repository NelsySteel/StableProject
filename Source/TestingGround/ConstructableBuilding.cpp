// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructableBuilding.h"
#include "BuildingSpot.h"

// Sets default values
AConstructableBuilding::AConstructableBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}



void AConstructableBuilding::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	auto newColor = GetMaterial();
	if (m_currentColor != newColor)
	{
		SetColor(newColor);
		m_currentColor = newColor;
	}
}

void AConstructableBuilding::SetInfo_Implementation(const FBuildingSettings& info)
{
	BuildingInfo = info;
	auto comp_class = UBuildingPropertiesComponent::StaticClass();
	if (info.DetailsClass != nullptr)
	{
		comp_class = info.DetailsClass;
	}
	auto new_component = Cast<UBuildingPropertiesComponent>(AddComponentByClass(comp_class, false, {}, true));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Black, "Connected details component " + new_component->GetClass()->GetName());
}


void AConstructableBuilding::Move()
{
	m_currentState = Moving;
}

// Called when the game starts or when spawned
void AConstructableBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructableBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructableBuilding::SetPosition(const FVector& position)
{
	SetActorLocation(position);
}

void AConstructableBuilding::SetPosition(const FTransform& position)
{
	SetActorTransform(position);
}

bool AConstructableBuilding::StopMoving()
{
	if (m_currentState == Idle)
	{
		return false;
	}
	OnFinishMoving.Broadcast();
	m_currentState = Idle;
	if (PlacedCorrectly())
	{
		auto firstPlacement = !m_isAlreadyInWorld;
		m_isAlreadyInWorld = true;
		m_originalTransform = GetActorTransform();
		return firstPlacement;
	}
	if (m_isAlreadyInWorld)
	{
		SetActorTransform(m_originalTransform);
		return false;
	}
	Destroy();
	return false;
}

AActor* AConstructableBuilding::CreateBuildingChild()
{
	auto childComp = Cast<UChildActorComponent>(AddComponentByClass(UChildActorComponent::StaticClass(), false, {}, true));
	childComp->SetChildActorClass(GetInfo().ChildActorClass);
	childComp->CreateChildActor();
	childComp->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	return childComp->GetChildActor();
}

void AConstructableBuilding::ProcessActorBeginOverlap(AActor* overlappedActor)
{
	if (m_currentState == Moving)
	{
		m_overlappedActors.AddUnique(overlappedActor);
	}
}

void AConstructableBuilding::ProcessActorEndOverlap(AActor* overlappedActor)
{
	if (m_currentState == Moving)
	{
		if (m_overlappedActors.Find(overlappedActor) != INDEX_NONE)
		{
			m_overlappedActors.Remove(overlappedActor);
		}
	}
}

TEnumAsByte<BuildingColor> AConstructableBuilding::GetMaterial() const
{
	if (m_currentState == Idle)
	{
		return Color_Normal;
	}
	if (m_currentState == Moving && PlacedCorrectly())
	{
		return Color_Available;
	}
	return Color_Inavailable;
}

