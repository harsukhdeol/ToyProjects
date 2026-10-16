// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams
(FOnInventoryChanged, FName, ItemId, int32, NewCount);


UCLASS(ClassGroup = (Potion), meta = (BlueprintSpawnableComponent))
class TOYPROJECTS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Potion|Inventory")
	void AddItem(FName ItemId, int32 Amount = 1);

	UFUNCTION(BlueprintCallable, Category = "Potion|Inventory")
	bool RemoveItem(FName ItemId, int32 Amount = 1);

	UFUNCTION(BlueprintCallable, Category = "Potion|Inventory")
	int32 GetCount(FName ItemId) const;

	UFUNCTION(BlueprintCallable, Category = "Potion|Inventory")
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
