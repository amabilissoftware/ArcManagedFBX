#include "Stdafx.h"
#include "FBXFileTexture.h"

using namespace ArcManagedFBX;

FBXFileTexture::FBXFileTexture()
{

}

FBXFileTexture::FBXFileTexture(FbxFileTexture* instance) : FBXTexture(instance)
{
}

FBXFileTexture::~FBXFileTexture()
{

}

FBXFileTexture::!FBXFileTexture()
{

}

void ArcManagedFBX::FBXFileTexture::SetMaterialUse(EMaterialUse materialUse)
{
	this->GetFBXFileTexture()->SetMaterialUse((fbxsdk::FbxFileTexture::EMaterialUse)materialUse);
}

bool ArcManagedFBX::FBXFileTexture::SetFileName(String^ fileName)
{
	return this->GetFBXFileTexture()->SetFileName(StringHelper::ToNative(fileName));
}

