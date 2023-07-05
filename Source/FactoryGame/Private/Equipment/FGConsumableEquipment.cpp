// This file has been automatically generated by the Unreal Header Implementation tool

#include "Equipment/FGConsumableEquipment.h"
#include "Equipment/FGEquipment.h"

AFGConsumableEquipment::AFGConsumableEquipment() : Super() {
	this->mEquipmentSlot = EEquipmentSlot::ES_ARMS;
	this->mArmAnimation = EArmEquipment::AE_Consumables;
	this->mDefaultEquipmentActions = 1;
}
bool AFGConsumableEquipment::ShouldSaveState() const{ return bool(); }
void AFGConsumableEquipment::Server_Consume_Implementation(){ }
void AFGConsumableEquipment::Consume(){ }
void AFGConsumableEquipment::GetConsumeable(TSubclassOf<  UFGConsumableDescriptor >& out_consumeable, int32& out_numConsumeable) const{ }
void AFGConsumableEquipment::PlayConsumeEffects_Implementation( UFGConsumableDescriptor* consumable){ }
void AFGConsumableEquipment::HandleDefaultEquipmentActionEvent(EDefaultEquipmentAction action, EDefaultEquipmentActionEvent actionEvent){ }
