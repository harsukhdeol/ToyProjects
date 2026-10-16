// Fill out your copyright notice in the Description page of Project Settings.


#include "PotionCatalog.h"
#include "Engine/DataTable.h"

namespace
{
	//creating a new template for any row type
	template<typename RowType>
	const RowType* FindRowSafe(const UDataTable* Table, FName Id)
	{
		return Table ? Table->
			FindRow<RowType>(Id, TEXT("UPotionCatalog"), false) : nullptr;
	}

	TArray<FName> RowNamesOf(const UDataTable* Table)
	{
		return Table ? Table->GetRowNames() : TArray<FName>();
	}
}

const FIngredientRow* UPotionCatalog::FindIngredient(FName Id) const
{
	return FindRowSafe<FIngredientRow>(IngredientTable, Id);
}

const FPotionRecipeRow* UPotionCatalog::FindRecipe(FName Id) const
{
	return FindRowSafe<FPotionRecipeRow>(RecipeTable, Id);
}

const FOrderTemplateRow* UPotionCatalog::FindOrderTemplate(FName Id) const
{
	return FindRowSafe<FOrderTemplateRow>(OrderTemplateTable, Id);
}

TArray<FName> UPotionCatalog::GetOrderTemplateIDs() const
{
	return RowNamesOf(OrderTemplateTable);
}

TArray<FName> UPotionCatalog::GetIngredientIds() const
{
	return RowNamesOf(IngredientTable);
}

TArray<FName> UPotionCatalog::GetRecipeIds() const
{
	return RowNamesOf(RecipeTable);
}

TArray<FName> UPotionCatalog::GetUnlockedIngredientIds(int32 Level) const
{
	TArray<FName> Result;
	for (const FName& Id : GetIngredientIds())
	{
		const FIngredientRow* Row = FindIngredient(Id);
		if (Row && Row->UnlockLevel <= Level)
		{
			Result.Add(Id);
		}
	}
	return Result;
}

bool UPotionCatalog::GetIngredient(FName Id, FIngredientRow& OutRow) const
{
	if (const FIngredientRow* Row = FindIngredient(Id))
	{
		OutRow = *Row;
		return true;
	}
	return false;
}

bool UPotionCatalog::GetRecipe(FName Id, FPotionRecipeRow& OutRow) const
{
	if (const FPotionRecipeRow* Row = FindRecipe((Id)))
	{
		OutRow = *Row;
		return true;
	}
	return false;
}