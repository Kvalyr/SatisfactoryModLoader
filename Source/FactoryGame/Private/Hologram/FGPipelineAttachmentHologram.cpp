// This file has been automatically generated by the Unreal Header Implementation tool

#include "Hologram/FGPipelineAttachmentHologram.h"
#include "Buildables/FGBuildablePipeline.h"
#include "FGPipeAttachmentSnapTargetInterface.h"

AFGPipelineAttachmentHologram::AFGPipelineAttachmentHologram() : Super() {
	this->mUseProducerDirectionalArrow = true;
	this->mProducerArrowRelativeLocation = FVector((0, 0, 200));
	this->mBasePipeClass = AFGBuildablePipeline::StaticClass();
	this->mPipeAttachmentInterfaceClass = UFGPipeAttachmentSnapTargetInterface::StaticClass();
}
void AFGPipelineAttachmentHologram::BeginPlay(){ }
void AFGPipelineAttachmentHologram::ConfigureComponents(AFGBuildable* inBuildable) const{ }
