// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "Equipment/FGBuildGun.h"
#include "ItemAmount.h"
#include "FGBuildableSubsystem.h"
#include "FGConstructionMessageInterface.h"
#include "Delegates/DelegateCombinations.h"
#include "FGFactoryBlueprintTypes.h"
#include "FGBuildGunBuild.generated.h"

/** Used to define reasons for failing to perform a nudge. */
UENUM( BlueprintType )
enum class ENudgeFailReason : uint8
{
	NFR_Success				UMETA( DisplayName = "Success" ),
	
	NFR_InvalidHologram		UMETA( DisplayName = "Invalid Hologram" ),
	NFR_Disallowed			UMETA( DisplayName = "Disallowed" ),
	NFR_IllegalMove			UMETA( DisplayName = "Illegal Move" ),
	NFR_ExceedMaxDistance	UMETA( DisplayName = "Exceeding Max Distance" ),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FHologramLockStateChanged, class AFGHologram*, hologram, bool, locked );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FHologramNudgeOffsetChanged, class AFGHologram*, hologram, const FVector&, offset );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FHologramNudgeFailed, class AFGHologram*, hologram, ENudgeFailReason, reason );

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams( FOnZoopUpdated, float, currentZoop, float, maxZoop, const FVector&, zoopLocation );

USTRUCT()
struct FConnectionRepresentation
{
	GENERATED_BODY()

	FConnectionRepresentation() :
		mConnectionComponent( nullptr ),
		mConnectionRepresentation( nullptr )
	{
	}

	FConnectionRepresentation( class UFGConnectionComponent* connectionComponent, class UStaticMeshComponent * connectionRepresentation ) :
		mConnectionComponent(connectionComponent),
		mConnectionRepresentation(connectionRepresentation)
	{
	}

	UPROPERTY()
	class UFGConnectionComponent* mConnectionComponent;

	UPROPERTY()
	class UStaticMeshComponent* mConnectionRepresentation;
};

USTRUCT()
struct FAttachmentPointRepresentation
{
	GENERATED_BODY()

	FAttachmentPointRepresentation() :
		mAttachmentPoint( nullptr ),
		mAttachmentRepresentation( nullptr )
	{
	}

	FAttachmentPointRepresentation( const struct FFGAttachmentPoint* attachmentPoint, class UStaticMeshComponent* attachmentRepresentation ) :
		mAttachmentPoint( attachmentPoint ),
		mAttachmentRepresentation( attachmentRepresentation )
	{
	}

	const struct FFGAttachmentPoint* mAttachmentPoint;

	UPROPERTY()
	class UStaticMeshComponent* mAttachmentRepresentation;
};

USTRUCT()
struct FActorClearanceData
{
	GENERATED_BODY()

	FActorClearanceData() :
		Actor( nullptr ),
		BlueprintProxyMesh( nullptr )
	{
	}

	FActorClearanceData( class AActor* inActor ) :
		Actor( inActor ),
		BlueprintProxyMesh( nullptr )
	{
	}

	UPROPERTY()
	class AActor* Actor;

	UPROPERTY()
	TArray< class UStaticMeshComponent* > ClearanceMeshComponents;

	UPROPERTY()
	class UStaticMeshComponent* BlueprintProxyMesh;

	UPROPERTY()
	TArray< FConnectionRepresentation > mConnectionComponents;

	UPROPERTY()
	TArray< FAttachmentPointRepresentation > mAttachmentPointMeshes;

	UPROPERTY()
	TArray< class UBoxComponent* > OverlappingClearanceDetectors;
};

/**
 * Build guns build state.
 */
UCLASS()
class FACTORYGAME_API UFGBuildGunStateBuild : public UFGBuildGunState
{
	GENERATED_BODY()

public:
	/** Ctor */
	UFGBuildGunStateBuild();

	/** Replication. */
	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty >& OutLifetimeProps ) const override;

	// Begin UFGBuildGunState
	virtual void BeginState_Implementation() override;
	virtual void EndState_Implementation() override;
	virtual void TickState_Implementation( float deltaTime ) override;
	virtual void PrimaryFire_Implementation() override;
	virtual void PrimaryFireRelease_Implementation() override;
	virtual void SecondaryFire_Implementation() override;
	virtual void Scroll_Implementation( int32 delta ) override;
	virtual void BuildSampleRelease_Implementation() override;
	virtual bool IsValidBuildingSample( class AFGBuildable* buildable ) const override;
	virtual bool IsValidVehicleSample( class AFGVehicle* vehicle ) const override;
	virtual void OnRecipeSampled_Implementation( TSubclassOf<class UFGRecipe> recipe ) override;
	virtual void OnBuildGunModeChanged_Implementation( TSubclassOf< UFGBuildGunModeDescriptor > newMode ) override;
	virtual void GetSupportedBuildModes_Implementation( TArray< TSubclassOf< UFGBuildGunModeDescriptor > >& out_buildModes) const override;
	virtual float GetBuildGunRangeOverride_Implementation() override;
	virtual void BindInputActions( class UFGEnhancedInputComponent* inputComponent ) override;
	// End UFGBuildGunState

	/**
	 * Set the recipe to build.
	 * must be called from the local player (client).
	 */
	void SetActiveRecipe( TSubclassOf< class UFGRecipe > recipe );
	TSubclassOf< class UFGRecipe > GetActiveRecipe() const { return mActiveRecipe; }

	/**
	 * Set active blueprint descriptor. This will be used when a blueprint hologram recipe is set
	 */
	void SetActiveBlueprintDescriptor( UFGBlueprintDescriptor* blueprintDesc );
	UFGBlueprintDescriptor* GetActiveBlueprintDescriptor( ) { return mActiveBlueprintDescriptor; }

	/** Get the current descriptor, null if no descriptor is set. */
	UFUNCTION( BlueprintPure, Category = "BuildGunState|Build" )
	TSubclassOf< class UFGItemDescriptor > GetDescriptor() const;

	/** Returns the cost for building the hologram. */
	UFUNCTION( BlueprintPure, Category = "BuildGunState|Build" )
	TArray< FItemAmount > GetHologramCost() const;

	/** Returns the hologram; null if hologram not spawned. */
	UFUNCTION( BlueprintPure, Category = "BuildGunState|Build" )
	class AFGHologram* GetHologram() const;

	/** Spawns a child hologram */
	AFGHologram* SpawnChildHologram( AFGHologram* parent, TSubclassOf< class UFGRecipe > recipe );

	/** RPC to construct from hologram data */
	UFUNCTION( Server, Reliable )
	void Server_ConstructHologram( FNetConstructionID clientNetConstructID, FConstructHologramMessage data );
	void InternalConstructHologram( FNetConstructionID clientNetConstructID );

	UFUNCTION( Server, Reliable )
    void Server_ChangeGuideLinesSnapMode( bool enabled );
	void ChangeGuidelineSnapMode( bool enabled );

	UFUNCTION( Server, Reliable )
	void Server_ToggleHologramPositionLock();
	void ToggleHologramPositionLock();

	UFUNCTION( BlueprintPure, Category = "BuildModeSelect" )
	TSubclassOf<class UFGHologramBuildModeDescriptor> GetLastBuildModeForCategory( uint8 category, TSubclassOf< class AActor > actorClass );

	/** Called whenever a hologram updates its zoop.
	 * @param currentZoop - How far we have zooped, value depends on hologram implementation. Beams use meters, cosmetic buildables use number of instances.
	 * @param maxZoop - How far we are allowed to zoop with the current hologram.
	 * @param zoopLocation - The location we're zooping to.
	 */
	UFUNCTION( BlueprintNativeEvent, Category = "Hologram" )
	void OnZoopUpdated( float currentZoop, float maxZoop, const FVector& zoopLocation );

	/** Called whenever a hologram updates its zoop. */
	UPROPERTY( BlueprintAssignable, Category = "Hologram", DisplayName = "OnZoopUpdated" )
	FOnZoopUpdated OnZoopUpdatedDelegate;

	void OnHologramLockStateChanged( class AFGHologram* hologram, bool isLocked );

	UPROPERTY( BlueprintAssignable, Category = "Hologram", DisplayName = "OnHologramLockStateChanged" )
	FHologramLockStateChanged OnHologramLockStateChangedDelegate;

	void OnHologramNudgeOffsetChanged( class AFGHologram* hologram, const FVector& newOffset );

	UPROPERTY( BlueprintAssignable, Category = "Hologram", DisplayName = "OnHologramNudgeOffsetChanged" )
	FHologramNudgeOffsetChanged OnHologramNudgeOffsetChangedDelegate;

	UPROPERTY( BlueprintAssignable, Category = "Hologram", DisplayName = "OnHologramNudgeFailed" )
	FHologramNudgeFailed OnHologramNudgeFailedDelegate;

	void HookUpUserSettings();

	void OnClearanceDetectorAdded( UBoxComponent* clearanceDetector );

protected:
	
	/** InternalExecuteDuBuildStepInput
	 * Execute the actual build step logic. Called from primary fire, and sometimes from primary fire release
	 * 
	 */
	 void InternalExecuteDuBuildStepInput(bool isInputFromARelease);

	/**
	 * Resets any changes made to the hologram.
	 * @note Must be called on the server.
	 */
	UFUNCTION( BlueprintCallable, Category = "BuildGunState|Build" )
	void ResetHologram();

	/**
	 * Let blueprint know when we get a new descriptor, the new descriptor may be null.
	 */
	UFUNCTION( BlueprintImplementableEvent, Category = "BuildGunState|Build" )
	void OnActiveDescriptorChanged();

	/**
	 * Let blueprint know we performed a multi-step placement.
	 * @param isFinalStep - true if this was the last step, the thing is now built. Hologram is no longer guaranteed to exist on the the client.
	 */
	UFUNCTION( BlueprintImplementableEvent, Category = "BuildGunState|Build" )
	void OnMultiStepPlacement( bool isFinalStep );

	/**
	 * Let blueprint know we reset the multi-step placement.
	 */
	UFUNCTION( BlueprintImplementableEvent, Category = "BuildGunState|Build" )
	void OnResetHologram();

	/** Helper to notify the client that something was built. @todok2 remove this and use the other ones for recipe and blueprint below.
	 * Didn't want to change this behaviour on main so we have an extra call for now to make sure old systems don't break */
	UFUNCTION( Client, Reliable )
	void Client_OnBuildableConstructed( TSubclassOf< UFGItemDescriptor > desc );

	/** Helper to notify the client that a recipe was used to construct buildings */
	UFUNCTION( Client, Reliable )
	void Client_OnRecipeBuilt( TSubclassOf< class UFGRecipe > recipe, int32 numConstructed );
	
	/** Helper to notify the client that a blueprint was built */
	UFUNCTION( Client, Reliable )
	void Client_OnBlueprintConstructed( const FString& blueprintName, int32 numConstructed );

	UFUNCTION( Client, Reliable )
	void Client_OnBuildableFailedConstruction( FNetConstructionID netConstructionID );

private:
	/** Spawn a hologram. */
	void SpawnHologram();

	/** Remove the current hologram. */
	void RemoveHologram();

	/** Remove the clearance from our current hologram */
	void CleanupHologramClearanceDetection();

	AFGHologram* InternalSpawnHologram();

	UFUNCTION()
	void BeginClearanceDetectorOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult );

	UFUNCTION()
	void EndClearanceDetectorOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex );

	UFUNCTION()
	void OnUserSettingsUpdated();

	UFUNCTION( Server, Reliable )
	void Server_SetUseAutomaticClearanceSnapping( bool useAutomaticSnapping );

	/** Input Action Bindings */
	void Input_HologramLock( const FInputActionValue& actionValue );
	void Input_HologramNudgeAxis( const FInputActionValue& actionValue );
	void Input_SnapToGuideLines( const FInputActionValue& actionValue );
	
private:
	/** stores a time we have held the primary fire button for. Used so we can detect if it's a hold or tap or similar*/
	float mPrimaryFireHoldTime = -1;

	/** user setting for if we are using the release and press mode or not for advancing build steps. Nett to be in sync on client and ser ver players preferences*/
	UPROPERTY( Replicated )
	bool mIsUsingPressAndReleaseAsBuildSteps = true;


	bool mAllowAutomaticClearanceSnapping = false;

	/** Stored flag for whether hologram builds should snap to guide lines */
	bool mSnapToGuideLinesMode;

	/** Stored flag for whether hologram builds should snap to guide lines */
	bool mPrimaryDownStarted = false; //stores if we have started a primary fire press, so we know to respond to release presses too, so we don't get the release from a previous state or something

	int32 mPreviousScrollRotation;
	
	/** Recipe to activate when state is entered. */
	UPROPERTY()
	TSubclassOf< class UFGRecipe > mPendingRecipe;

	/**
	 * The currently active recipe, this decides which action will be used.
	 * Not replicated as the client sets it locally and then tells the server to set it.
	 */
	UPROPERTY()
	TSubclassOf< class UFGRecipe > mActiveRecipe;

	/** Map used to cache the last used build modes for different categories (keys). */
	TMap< uint8, TSubclassOf< class UFGHologramBuildModeDescriptor > > mLastUsedCategoryBuildmodes;

	/** Map used to cache the last used build modes for different actor class types. */
	TMap< TSubclassOf< class AActor >, TSubclassOf< class UFGHologramBuildModeDescriptor > > mLastUsedActorBuildmodes;

	//@TODO:[DavalliusA:Wed/20-11-2019] should these not be marked as transient?
	/** The hologram to build. */
	UPROPERTY( /*ReplicatedUsing=OnRep_Hologram */ )
	class AFGHologram* mHologram;

	//@TODO:[DavalliusA:Wed/20-11-2019] should these not be marked as transient?
	/** The actor to replace (dismantle) when upgrading. */
	UPROPERTY()
	class AActor* mUpgradedActor;

	/** Moves the clearance box collision to where we are aiming */
	void UpdateClearanceData();

	/** Contains all the proximate clearances volumes */
	UPROPERTY()
	TArray< FActorClearanceData > mProximateClearances;

	/** Component that finds close clearances of nearby buildings and visualize them */
	//@todo G2 2019-04-10 An improvement here would be to make this a component that can keep track of detected
	//                    overlaps so the state does not contain this easily self contained logic.
	UPROPERTY( Transient )
	TArray< class UBoxComponent* > mClearanceDetectors;

	/** All building locations spawned during this frame. Will be cleared at the start of every new frame to avoid spawning multiple buildings at the same location. */
	TArray<FVector> mConstructionLocationDuringFrame;

	UPROPERTY()
	UFGBlueprintDescriptor* mActiveBlueprintDescriptor;
};
