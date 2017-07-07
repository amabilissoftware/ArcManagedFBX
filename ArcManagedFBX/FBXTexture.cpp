#include "Stdafx.h"
#include "FBXTexture.h"

using namespace ArcManagedFBX;

FBXTexture::FBXTexture()
{

}

FBXTexture::FBXTexture(FbxTexture* instance) : FBXObject(instance)
{
}

FBXTexture::~FBXTexture()
{

}

FBXTexture::!FBXTexture()
{

}

void ArcManagedFBX::FBXTexture::SetMappingType(EMappingType mappingType)
{
	this->GetFBXTexture()->SetMappingType((fbxsdk::FbxTexture::EMappingType)mappingType);
}

void ArcManagedFBX::FBXTexture::SetTextureUse(ETextureUse textureUse)
{
	this->GetFBXTexture()->SetTextureUse((fbxsdk::FbxTexture::ETextureUse)textureUse);
}

void ArcManagedFBX::FBXTexture::SetSwapUV(bool swapUV)
{
	this->GetFBXTexture()->SetSwapUV(swapUV);
}

void ArcManagedFBX::FBXTexture::SetTranslation(double u, double v)
{
	this->GetFBXTexture()->SetTranslation(u, v);
}

void ArcManagedFBX::FBXTexture::SetScale(double u, double v)
{
	this->GetFBXTexture()->SetScale(u, v);
}

void ArcManagedFBX::FBXTexture::SetRotation(double u, double v)
{
	this->GetFBXTexture()->SetRotation(u, v);
}
