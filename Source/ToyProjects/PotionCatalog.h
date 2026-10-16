// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PotionTypes.h"
#include "PotionCatalog.generated.h"

class UDataTable;

//read only access to all catalog content

UCLASS()
class TOYPROJECTS_API UPotionCatalog : public UDataAsset
{
	GENERATED_BODY()
	
public:
	//returns pointers into the tables
	const FIngredientRow* FindIngredient(FName Id) const;
	const FPotionRecipeRow* FindRecipe(FName Id) const;
	const FOrderTemplateRow* FindOrderTemplate(FName Id) const;

	TArray<FName> GetOrderTemplateIDs() const;

	// BP API: returns copies
	UFUNCTION (BlueprintCallable, Category = "Potion|Catalog")
	TArray<FName>GetIngredientIds() const;

	UFUNCTION(BlueprintCallable, Category = "Potion|Catalog")
	TArray<FName>GetRecipeIds() const;

	UFUNCTION(BlueprintCallable, Category = "Potion|Catalog")
	TArray<FName> GetUnlockedIngredientIds(int32 Level) const;

	UFUNCTION(BlueprintCallable, Category = "Potion|Catalog")
	bool GetIngredient(FName Id, FIngredientRow& OutRow) const;

	UFUNCTION(BlueprintCallable, Category = "Potion|Catalog")
	bool GetRecipe(FName Id, FPotionRecipeRow& OutRow) const;

protected:
	UPROPERTY(EditAnywhere, Category = "Tables")
	TObjectPtr<UDataTable> IngredientTable;

	UPROPERTY(EditAnywhere, Category = "Tables")
	TObjectPtr<UDataTable> RecipeTable;

	UPROPERTY(EditAnywhere, Category = "Tables")
	TObjectPtr<UDataTable> OrderTemplateTable;

	
};
