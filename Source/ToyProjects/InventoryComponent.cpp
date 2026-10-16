
#include "InventoryComponent.h"
#include "ToyProjects.h"

// Sets default values
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInventoryComponent::AddItem(FName ItemId, int32 Amount)
{
	if(ItemId.IsNone() || Amount <= 0)
	{
		return;
	}
	int32 Count = Items.FindOrAdd(ItemId);
	Count += Amount;
	OnInventoryChanged.Broadcast(ItemId, Count);
}

bool UInventoryComponent::RemoveItem(FName ItemId, int32 Amount)
{
	if(Amount<=0)
	{
		return false;
	}

	int32* Count = Items.Find(ItemId);

	if(!Count||*Count < Amount)
	{
		return false;
	}

	*Count -= Amount;
	const int32 NewCount = *Count;

	if (NewCount == 0)
	{
		Items.Remove(ItemId);
	}
	OnInventoryChanged.Broadcast(ItemId, *Count);

	return true;
}

int32 UInventoryComponent::GetCount(FName ItemId) const
{
	return Items.FindRef(ItemId);
}

void UInventoryComponent::LogContents() const
{
	UE_LOG(LogToyProjects, Log, TEXT("---Inventory (%d kinds)---"), Items.Num());
	for (const TPair<FName, int32>& Pair : Items)
	{
		UE_LOG(LogToyProjects, Log, TEXT(" %s x%d"), *Pair.Key.ToString(), Pair.Value);
	}
}

