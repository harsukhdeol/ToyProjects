// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Datatable.h"
#include "PotionTypes.generated.h"


class UTexture2d;

//ENUMS
UENUM (BlueprintType)
enum class EStirRating : uint8
{
	Miss,
	Good, 
	Perfect
};

UENUM(BlueprintType)
enum class EBrewPhase :uint8
{
	Idle,
	AddingIngredients,
	Stirring, 
	Cooking, 
	Result
};

//Data Table Rows

USTRUCT(BlueprintType)
struct FRecipeIngredient
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName IngredientID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "1"))
	int32 Count = 1;
};

USTRUCT(BlueprintType)
struct FIngredientRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "1"))
	int32 UnlockLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0"))
	int32 RestockPrice = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0"))
	int32 StartingAmount = 0;
};

USTRUCT(BlueprintType)
struct FPotionRecipeRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> Icon; // hard reference, ok for small obj

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FRecipeIngredient> Ingredients;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "1"))
	int32 StirBeats = 4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0.3"))
	float BeatIntervalSecs = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "1"))
	float IdealCookTime = 6.0f; // in seconds

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0.1"))
	float CookToleranceSecs = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "1"))
	int32 UnlockLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0"))
	int32 BaseCoins = 30;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0"))
	int32 BaseXP = 20;

};

USTRUCT (BlueprintType)
struct FOrderTemplateRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName CustomerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (MultiLine = "true"))
	FText ProblemText;

	//recipe id of the solution
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 RecipeId;

	//player level needed before this customer shows up
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "1"))
	int32 MinLevel = 1;
	
};

// Runtime data - created by the game

USTRUCT(BlueprintType)
struct FActiveOrder //copies text out of template 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 OrderID = 0;

	UPROPERTY(BlueprintReadOnly)
	FName RecipeId;

	UPROPERTY(BlueprintReadOnly)
	FText CustomerName;

	UPROPERTY(BlueprintReadOnly)
	FText ProblemText;
};

USTRUCT(BlueprintType)
struct FBrewResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FName RecipeId;

	UPROPERTY(BlueprintReadOnly)
	float StirScore = 0.f;

	UPROPERTY(BlueprintReadOnly)
	float CookScore = 0.f;

	UPROPERTY(BlueprintReadOnly)
	float Quality = 0.f;

	UPROPERTY(BlueprintReadOnly)
	int32 Stars = 0;

	UPROPERTY(BlueprintReadOnly)
	bool bBurnt = false;
};

USTRUCT(BlueprintType)
struct FDeliveryReport
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FBrewResult Brew;

	UPROPERTY(BlueprintReadOnly)
	int32 CoinsEarned = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 XPEarned = 0;

	UPROPERTY(BlueprintReadOnly)
	bool bFulfilledOrder = false;
};
class TOYPROJECTS_API PotionTypes
{
public:
	PotionTypes();
	~PotionTypes();
};
