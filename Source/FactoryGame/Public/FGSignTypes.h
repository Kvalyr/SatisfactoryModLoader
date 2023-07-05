// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once


#include "FactoryGame.h"
#include "UMG.h"
#include "FGSignTypes.generated.h"




// Blueprint Data class for holding information that can be shared between multiple FGBuildableWidgetSign classes
UCLASS( Blueprintable, Abstract )
class FACTORYGAME_API UFGSignTypeDescriptor : public UObject
{
	GENERATED_BODY()

public:
	UFGSignTypeDescriptor();

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	bool IsValidElementName( const FString& elementName ) 
	{
		TArray< FString > keys;
		mTextElementNameMap.GenerateKeyArray( keys );
		if( keys.Contains( elementName ) )
		{
			return true;
		}

		keys.Empty();
		mIconElementNameMap.GenerateKeyArray( keys );
		if( keys.Contains( elementName ) )
		{
			return true;
		}

		return false;
	}

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	FORCEINLINE FVector2D GetSignCanvasDimensions() { return mSignCanvasDimensions; }

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	FORCEINLINE FLinearColor GetDefaultForegroundColor() { return mDefaultForegroundColor; }

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	FORCEINLINE FLinearColor GetDefaultBackgroundColor() { return mDefaultBackgroundColor; }

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	FORCEINLINE FLinearColor GetDefaultAuxiliaryColor() { return mDefaultAuxiliaryColor; }

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	TMap< FString, FString >& GetTextElementNameMap() { return mTextElementNameMap; }

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	TMap< FString, class UObject* >& GetIconElementNameMap() { return mIconElementNameMap; }

	UFUNCTION( BlueprintPure, Category = "Sign Data" )
	TArray< TSubclassOf< UFGSignPrefabWidget > >& GetPrefabArray() { return mPrefabArray; }


public:
	
	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	FVector2D mSignCanvasDimensions;

	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	FLinearColor mDefaultForegroundColor;

	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	FLinearColor mDefaultBackgroundColor;

	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	FLinearColor mDefaultAuxiliaryColor;

	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	TMap< FString, FString > mTextElementNameMap;

	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	TMap< FString, class UObject* > mIconElementNameMap;

	UPROPERTY( EditDefaultsOnly, Category = "Sign Data" )
	TArray< TSubclassOf< class UFGSignPrefabWidget > > mPrefabArray;


};


/**
 *	Stuct for saving out text data that can be converted back into a TMap for ease of use
 */
USTRUCT()
struct FACTORYGAME_API FPrefabTextElementSaveData
{
	GENERATED_BODY()

	UPROPERTY( SaveGame )
	FString ElementName;

	UPROPERTY( SaveGame )
	FString Text;
};

/**
 *	Stuct for saving out icon data that can be converted back into a TMap for ease of use
 */
USTRUCT()
struct FACTORYGAME_API FPrefabIconElementSaveData
{
	GENERATED_BODY()

	UPROPERTY( SaveGame )
	FString ElementName;

	UPROPERTY( SaveGame )
	int32 IconID;
};



/**
 * Structure for passing sign save data to and from blueprint so that it is compiled into one location before delivery
 */
USTRUCT( BlueprintType )
struct FACTORYGAME_API FPrefabSignData
{
	GENERATED_BODY()

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	TSubclassOf< UUserWidget > PrefabLayout = {};

	UPROPERTY( BlueprintReadWrite, NotReplicated, Category = "Prefab Sign Data" )
	TMap< FString, FString > TextElementData = {};

	UPROPERTY( BlueprintReadWrite, NotReplicated, Category = "Prefab Sign Data" )
	TMap< FString, int32 > IconElementData = {};

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	FLinearColor ForegroundColor = FLinearColor::Black;

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	FLinearColor BackgroundColor = FLinearColor::Black;

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	FLinearColor AuxiliaryColor = FLinearColor::Black;

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	float Emissive = 0.f;

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	float Glossiness = 0.f;

	UPROPERTY( BlueprintReadWrite, Category = "Prefab Sign Data" )
	TSubclassOf < UFGSignTypeDescriptor > SignTypeDesc = {};

	
	// For clients to know if they should call the server RPC to set the data when they receive new data (if from replication don't trigger the RPC as it came from an RPC)
	bool IsFromReplication = false;

	uint32 GetGUID() const;
};


UCLASS( Blueprintable, Abstract )
class FACTORYGAME_API UFGSignPrefabWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable, Category = "Sign Data" )
	void SetNameToTextWidgetMap( TMap<FString, class URichTextBlock*>& textWidgetMap ) 
	{
		mNameToTextWidget.Empty();
		mNameToTextWidget.Append( textWidgetMap );
	}

	UFUNCTION( BlueprintCallable, Category = "Sign Data" )
	void SetNameToIconWidgetMap( TMap< FString, class UImage* >& iconWidgetMap )
	{
		mNameToIconWidget.Empty();
		mNameToIconWidget.Append( iconWidgetMap );
	}

	// Getters
	TMap< FString, class URichTextBlock* > GetNameToTextWidgetMap() { return mNameToTextWidget; }
	TMap< FString, class UImage* > GetNameToIconWidgetMap() { return mNameToIconWidget; }

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Sign Data" )
	bool bContainsIcon;

	// The prefab data for this widget - Changes per instance
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Transient, Category = "Sign Data", meta=( ExposeOnSpawn ) )
	FPrefabSignData mPrefabSignData;

protected:
	UPROPERTY( BlueprintReadWrite, Category = "Sign Data" )
	TMap< FString, class URichTextBlock* > mNameToTextWidget;

	UPROPERTY( BlueprintReadWrite, Category = "Sign Data" )
	TMap< FString, class UImage* > mNameToIconWidget;
};
