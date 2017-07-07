#include "Stdafx.h"
#include "FBXSurfaceMaterial.h"

using namespace ArcManagedFBX;

FBXSurfaceMaterial::FBXSurfaceMaterial()
{

}

FBXSurfaceMaterial::FBXSurfaceMaterial(FbxSurfaceMaterial* instance) : FBXObject(instance)
{
}

FBXSurfaceMaterial::~FBXSurfaceMaterial()
{

}

FBXSurfaceMaterial::!FBXSurfaceMaterial()
{

}

void ArcManagedFBX::FBXSurfaceMaterial::SetShadingModel(String^ value)
{
	this->GetFBXSurfaceMaterial()->ShadingModel = StringHelper::ToNative(value);
}
void ArcManagedFBX::FBXSurfaceMaterial::SetMultiLayer(bool value)
{
	this->GetFBXSurfaceMaterial()->MultiLayer = value;
}