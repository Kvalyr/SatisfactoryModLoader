// This file has been automatically generated by the Unreal Header Implementation tool

#include "Equipment/FGEquipment.h"

AFGEquipment::AFGEquipment() : Super() {
	this->mAttachmentClass = nullptr;
	this->mSecondaryAttachmentClass = nullptr;
	this->mEquipmentSlot = EEquipmentSlot::ES_NONE;
	this->mSprintHeadBobShake = nullptr;
	this->mEquipSound = nullptr;
	this->mUnequipSound = nullptr;
	this->mEquipmentWidget = nullptr;
	this->mChildEquipment = nullptr;
	this->m1PAnimClass = nullptr;
	this->mAttachSocket = TEXT("None");
	this->mChildEquipmentClass = nullptr;
	this->mArmAnimation = EArmEquipment::AE_None;
	this->mBackAnimation = EBackEquipment::BE_None;
	this->mHasPersistentOwner = false;
	this->mOnlyVisibleToOwner = true;
	this->mAttachment = nullptr;
	this->mSecondaryAttachment = nullptr;
	this->mIdlePoseAnimation = nullptr;
	this->mIdlePoseAnimation3p = nullptr;
	this->mCrouchPoseAnimation3p = nullptr;
	this->mSlidePoseAnimation3p = nullptr;
	this->mUseDefaultPrimaryFire = false;
	this->mAttachmentIdleAO = nullptr;
	this->PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.EndTickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.bTickEvenWhenPaused = false;
	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = false;
	this->PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	this->PrimaryActorTick.TickInterval = 0.0;
	this->bNetUseOwnerRelevancy = true;
	this->bReplicates = true;
}
void AFGEquipment::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGEquipment, mChildEquipment);
	DOREPLIFETIME(AFGEquipment, mAttachment);
	DOREPLIFETIME(AFGEquipment, mSecondaryAttachment);
}
void AFGEquipment::PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker){ }
void AFGEquipment::OnRep_AttachmentReplication(){ }
void AFGEquipment::BeginPlay(){ }
void AFGEquipment::EndPlay(const EEndPlayReason::Type EndPlayReason){ }
void AFGEquipment::PreSaveGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGEquipment::PostSaveGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGEquipment::PreLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGEquipment::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGEquipment::GatherDependencies_Implementation(TArray< UObject* >& out_dependentObjects){ }
bool AFGEquipment::NeedTransform_Implementation(){ return bool(); }
bool AFGEquipment::ShouldSave_Implementation() const{ return bool(); }
void AFGEquipment::Equip( AFGCharacterPlayer* character){ }
void AFGEquipment::UnEquip(){ }
void AFGEquipment::OnCharacterMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode, EMovementMode NewMovementMode, uint8 NewCustomMode){ }
void AFGEquipment::OnDefaultPrimaryFirePressed(){ }
void AFGEquipment::UpdatePrimitiveColors(){ }
void AFGEquipment::Server_DefaultPrimaryFire_Implementation(){ }
bool AFGEquipment::Server_DefaultPrimaryFire_Validate(){ return bool(); }
void AFGEquipment::DoDefaultPrimaryFire_Native(){ }
bool AFGEquipment::CanDoDefaultPrimaryFire_Implementation(){ return bool(); }
void AFGEquipment::DisableEquipment(){ }
AFGCharacterPlayer* AFGEquipment::GetInstigatorCharacter() const{ return nullptr; }
void AFGEquipment::OnColorUpdate(int32 index){ }
bool AFGEquipment::IsLocalInstigator() const{ return bool(); }
bool AFGEquipment::ShouldSaveState() const{ return bool(); }
void AFGEquipment::SetAttachment( AFGEquipmentAttachment* newAttachment){ }
void AFGEquipment::SetSecondaryAttachment( AFGEquipmentAttachment* newAttachment){ }
void AFGEquipment::Server_UpdateAttachmentUseState_Implementation(int newUseState){ }
bool AFGEquipment::Server_UpdateAttachmentUseState_Validate(int newUseState){ return bool(); }
float AFGEquipment::AdjustDamage_Implementation(float damageAmount, const  UDamageType* damageType,  AController* instigatedBy, AActor* damageCauser){ return float(); }
EEquipmentSlot AFGEquipment::GetEquipmentSlot(TSubclassOf< AFGEquipment > inClass){ return EEquipmentSlot(); }
void AFGEquipment::SpawnChildEquipment(){ }
bool AFGEquipment::ShouldShowStinger() const{ return bool(); }
void AFGEquipment::WasRemovedFromSlot_Implementation(){ }
void AFGEquipment::WasSlottedIn_Implementation( AFGCharacterPlayer* holder){ }
void AFGEquipment::WasEquipped_Implementation(){ }
void AFGEquipment::WasUnEquipped_Implementation(){ }
void AFGEquipment::AddEquipmentHUD(){ }
void AFGEquipment::RemoveEquipmentHUD(){ }
void AFGEquipment::SetEquipmentTicks(bool inTick){ }
void AFGEquipment::AddEquipmentActionBindings(){ }
void AFGEquipment::ClearEquipmentActionBindings(){ }
bool AFGEquipment::CanAffordUse() const{ return bool(); }
void AFGEquipment::DidNotAffordUse_Implementation(){ }
void AFGEquipment::ChargeForUse(){ }
void AFGEquipment::Server_ChargeForUse_Implementation(){ }
bool AFGEquipment::Server_ChargeForUse_Validate(){ return bool(); }
void AFGEquipment::ChargeForUse_Internal(){ }
void AFGEquipment::OnChildEquipmentReplicated(){ }
