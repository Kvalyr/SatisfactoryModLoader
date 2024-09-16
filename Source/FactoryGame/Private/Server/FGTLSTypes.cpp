// This file has been automatically generated by the Unreal Header Implementation tool

#include "Server/FGTLSTypes.h"

void OSSLDataWrapperSerializers::SerializePublicKey(FArchive& Ar, TOSSLDataWrapper<EOSSLDataType::EVP_PKEY>& PublicKey) {}
void OSSLDataWrapperSerializers::SerializePrivateKey(FArchive& Ar, TOSSLDataWrapper<EOSSLDataType::EVP_PKEY>& PrivateKey) {}
void OSSLDataWrapperSerializers::SerializeX509(FArchive& Ar, TOSSLDataWrapper<EOSSLDataType::X509>& Certificate) {}
void OSSLDataWrapperInternals::RefDownDataInstance(EOSSLDataType DataType, void* DataInstance) {}
void OSSLDataWrapperInternals::RefUpDataInstance(EOSSLDataType DataType, void* DataInstance) {}
FString OSSLUtilities::FingerprintPublicKey(EVP_PKEY* PublicKey) { return TEXT(""); }