
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

	UFUNCTION(BlueprintPure, Category = "Potion|Inventory")
	int32 GetCount(FName ItemId) const;

	UPROPERTY(BlueprintAssignable, Category = "Potion|Inventory")
	FOnInventoryChanged OnInventoryChanged;

	void LogContents() const;


private:
	UPROPERTY(VisibleAnywhere, Category = "Potion|Inventory")
	TMap<FName, int32> Items;
};
