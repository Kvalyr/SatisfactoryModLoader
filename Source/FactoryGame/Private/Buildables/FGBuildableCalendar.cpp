// This file has been automatically generated by the Unreal Header Implementation tool

#include "Buildables/FGBuildableCalendar.h"

AFGBuildableCalendar::AFGBuildableCalendar() : Super() {
	this->mInventory = nullptr;
	this->mNumberOfSlotsInCalendar = 25;
	this->mCalendarRewardsClass = nullptr;
	this->mSlotFillerItemClass = nullptr;
	this->NetDormancy = ENetDormancy::DORM_Awake;
}
void AFGBuildableCalendar::BeginPlay(){ }
void AFGBuildableCalendar::EndPlay(const EEndPlayReason::Type EndPlayReason){ }
void AFGBuildableCalendar::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGBuildableCalendar, mInventory);
	DOREPLIFETIME(AFGBuildableCalendar, mReplicatedIndexMapping);
	DOREPLIFETIME(AFGBuildableCalendar, mOpenedSlotsInCalendar);
}
void AFGBuildableCalendar::GetDismantleRefund_Implementation(TArray< FInventoryStack >& out_refund, bool noBuildCostEnabled) const{ }
void AFGBuildableCalendar::OpenSlot(int32 dayNumber){ }
bool AFGBuildableCalendar::GetContentOnSlot(int32 dayNumber, FInventoryStack& out_slotContent){ return bool(); }
UFGUnlock* AFGBuildableCalendar::GetUnlockOnSlot(int32 dayNumber){ return nullptr; }
bool AFGBuildableCalendar::IsSlotOpened(int32 dayNumber) const{ return bool(); }
void AFGBuildableCalendar::OnInventoryItemRemoved(TSubclassOf< UFGItemDescriptor > itemClass, int32 numRemoved){ }
void AFGBuildableCalendar::StoreDataToEventSubsystem(){ }
