// This file has been automatically generated by the Unreal Header Implementation tool

#include "Creature/FGCreature.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"

TAutoConsoleVariable<int32> CVarCreatureDebug(TEXT("CVarCreatureDebug"), 0, TEXT(""));
TAutoConsoleVariable<int32> CVarCreatureVisionDebug(TEXT("CVarCreatureVisionDebug"), 0, TEXT(""));
void UFGCreatureInterruptTest::Initialize(APawn* pawn, AController* controller, UFGAction* ownerAction){ }
void UFGCreatureInterruptTest::Initialize(AFGCreature* creature, AFGCreatureController* controller){ }
#if WITH_EDITOR
void AFGCreature::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent){ Super::PostEditChangeProperty(PropertyChangedEvent); }
bool AFGCreature::IsSelectedInEditor() const{ return bool(); }
#endif 
#ifdef WITH_EDITOR
#endif 
AFGCreature::AFGCreature(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	this->mSpline = nullptr;
	this->mShouldOptimizeMeshWhenVisible = true;
	this->mNavAgentName = TEXT("Default");
	this->mNavBoundsScale = 1.0;
	this->mUseCapsuleRadiusInsteadOfBoundsForNavRadius = false;
	this->mNavigationGenerationRadius = 7000.0;
	this->mNavigationRemovalRadius = 8000.0;
	this->mRoamingDistance = FFloatInterval(500.0, 1000.0);
	this->mRoamingWaitTime = FFloatInterval(0.0, 5.0);
	this->mBehaviorTree = nullptr;
	this->mPerceptionSettings.SightConfig = nullptr;
	this->mPerceptionSettings.ImmediateVisibilityRadius = 500.0;
	this->mPerceptionSettings.HearingConfig = nullptr;
	this->mFleeStressThreshold = 0.0;
	this->mStressReductionRate = 0.0;
	this->mUnreachableTargetDamageStressMultiplier = 0.0;
	this->mDisabledBehaviorStates = 0;
	this->mCurrentBehaviorState = ECreatureState::CS_Default;
	this->mMaximumAggroLevel = 100.0;
	this->mAggroFightThreshold = 75.0;
	this->mAggroGainRateCurve = nullptr;
	this->mVisibilityGainRateCurve = nullptr;
	this->mAggroGainRate = 100.0;
	this->mAggroReductionRate = 5.0;
	this->mCreatureFamily = nullptr;
	this->mIsArachnid = false;
	this->mIsEnabled = EEnabled::E_Unknown;
	this->mItemToDrop = nullptr;
	this->mCreatureController = nullptr;
	this->mIsPersistent = false;
	this->mIsPassiveCreature = false;
	this->mPassiveHealthRegen = 0.0;
	this->mEyeLocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("EyeLocationComponent"));
	this->mArachnophobia_Sprite = nullptr;
	this->mArachnophobia_Material = nullptr;
	this->mArachnophobia_Particle = nullptr;
	this->mDayTimePctCountAsNight = 0.0;
	this->mSpawnDistance = 10000.0;
	this->mDespawnDistance = 12000.0;
	this->mOwningSpawner = nullptr;
	this->mCanBeStunned = true;
	this->mCanBeStunnedByDamage = true;
	this->mStunDamageThreshold = 0.0;
	this->mStunDamageDuration = 1.0;
	this->mStunDamageCooldownDuration = 5.0;
	this->mStunDamageReductionRate = 1.0;
	this->mIsStunned = false;
	this->bUseControllerRotationYaw = false;
	this->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	this->mEyeLocationComponent->SetupAttachment(GetCapsuleComponent());
}
void AFGCreature::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGCreature, mCurrentBehaviorState);
	DOREPLIFETIME(AFGCreature, mIsEnabled);
	DOREPLIFETIME(AFGCreature, mIsStunned);
}
void AFGCreature::BeginPlay(){ }
void AFGCreature::PreInitializeComponents(){ Super::PreInitializeComponents(); }
void AFGCreature::PostInitializeComponents(){ Super::PostInitializeComponents(); }
void AFGCreature::OnConstruction(const FTransform& Transform){ }
void AFGCreature::PostLoad(){ Super::PostLoad(); }
void AFGCreature::PossessedBy(AController* NewController){ }
void AFGCreature::UnPossessed(){ }
void AFGCreature::BeginDestroy(){ Super::BeginDestroy(); }
void AFGCreature::GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const{ }
void AFGCreature::RenameActionArrayEntries(){ }
void AFGCreature::UpdateCreatureNavAgentProps(){ }
bool AFGCreature::IsReadyToDespawn() const{ return bool(); }
bool AFGCreature::ShouldSave_Implementation() const{ return bool(); }
void AFGCreature::Died(AActor* died){ }
void AFGCreature::DoRagdoll_Internal(){ }
FVector AFGCreature::GetPawnViewLocation() const{ return FVector(); }
UFGCreatureMovementComponent* AFGCreature::GetCreatureCharacterMovement() const{ return nullptr; }
bool AFGCreature::GetAdjustedNavAgentProps(FNavAgentProperties& out_navAgentProps, UWorld* worldContext) const{ return bool(); }
void AFGCreature::ConfigureArachnophobiaMode_Implementation(bool isArachnophobiaMode){ }
void AFGCreature::OnArachnophobiaModeChanged(bool isArachnophobiaMode){ }
void AFGCreature::Multicast_ConsumeItem_Implementation(TSubclassOf<  UFGItemDescriptor > itemDescriptor, int32 amount){ }
void AFGCreature::SetMoveSpeed(EMoveSpeed newMoveSpeedType){ }
void AFGCreature::SpawnDeathItem_Implementation(){ }
UBehaviorTree* AFGCreature::GetOverrideBehaviorTreeForState(ECreatureState state) const{ return nullptr; }
bool AFGCreature::HasOverriddenBehaviorState(ECreatureState State) const{ return bool(); }
bool AFGCreature::IsCreatureStateEnabled(ECreatureState State) const{ return bool(); }
float AFGCreature::GetRandomRoamingWaitTime() const{ return float(); }
TArray<UFGAction*> AFGCreature::GetAvailableActionsForState(ECreatureState state){ return TArray<UFGAction*>(); }
TArray<UFGAction*> AFGCreature::GetAllCreatureActions() const{ return TArray<UFGAction*>(); }
void AFGCreature::ClearKillOrphanTimer(){ }
bool AFGCreature::CanBeStunned() const{ return bool(); }
bool AFGCreature::CanBeStunnedByDamage() const{ return bool(); }
void AFGCreature::BeginStun(float stunDuration){ }
void AFGCreature::EndStun(){ }
void AFGCreature::SetIsPersistent(bool persistent){ }
void AFGCreature::SetEnabled(EEnabled enabled){ }
void AFGCreature::OnRep_IsEnabled(){ }
void AFGCreature::OnRep_IsStunned(){ }
void AFGCreature::OnCreatureStateChanged( AFGCreatureController* creatureController, ECreatureState previousState, ECreatureState newState){ }
