// This file has been automatically generated by the Unreal Header Implementation tool

#include "Buildables/FGBuildablePassthrough.h"

AFGBuildablePassthrough::AFGBuildablePassthrough() : Super() {
	this->mSnappedBuildingThickness = 0.0;
	this->mMidMeshLength = 0.0;
	this->mGenerateTunnelCollision = false;
	this->mCapMesh = nullptr;
	this->mMidMesh = nullptr;
	this->mEndCapRotation.Pitch = 0.0;
	this->mEndCapRotation.Yaw = 0.0;
	this->mEndCapRotation.Roll = 0.0;
	this->mMidMeshRotation.Pitch = 0.0;
	this->mMidMeshRotation.Yaw = 0.0;
	this->mMidMeshRotation.Roll = 0.0;
	this->mClearanceHeightMin = 50.0;
	this->mClearanceThickness = 80.0;
	this->mUseSoftClearance = true;
	this->mBottomSnappedConnection = nullptr;
	this->mTopSnappedConnection = nullptr;
	this->mConnectionComponentClass = nullptr;
}
void AFGBuildablePassthrough::BeginPlay(){ }
void AFGBuildablePassthrough::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const{ }
void AFGBuildablePassthrough::StartIsLookedAtForDismantle_Implementation( AFGCharacterPlayer* byCharacter){ }
void AFGBuildablePassthrough::StopIsLookedAtForDismantle_Implementation( AFGCharacterPlayer* byCharacter){ }
void AFGBuildablePassthrough::GetChildDismantleActors_Implementation(TArray< AActor* >& out_ChildDismantleActors) const{ }
void AFGBuildablePassthrough::GetIgnoredBuildablesForClearanceOnSnap(TArray< AFGBuildable* >& out_ignoredBuildables){ }
bool AFGBuildablePassthrough::GetValidAttachDirection(FVector& out_validDir){ return bool(); }
void AFGBuildablePassthrough::SetBottomSnappedConnection( UFGConnectionComponent* connection){ }
void AFGBuildablePassthrough::SetTopSnappedConnection( UFGConnectionComponent* connection){ }
void AFGBuildablePassthrough::OnAttachedBuildableDismantled( AFGBuildable* dismantledBuildable){ }