#include "Stdafx.h"
#include "FBXSurfaceLambert.h"

using namespace ArcManagedFBX;

FBXSurfaceLambert::FBXSurfaceLambert()
{

}

FBXSurfaceLambert::FBXSurfaceLambert(FbxSurfaceLambert* instance) : FBXSurfaceMaterial(instance)
{
}

FBXSurfaceLambert::~FBXSurfaceLambert()
{

}

FBXSurfaceLambert::!FBXSurfaceLambert()
{

}

void ArcManagedFBX::FBXSurfaceLambert::SetEmissive(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->Emissive = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetEmissiveFactor(double value)
{
	this->GetFBXSurfaceLambert()->EmissiveFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::SetAmbient(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->Ambient = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetAmbientFactor(double value)
{
	this->GetFBXSurfaceLambert()->AmbientFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::SetDiffuse(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->Diffuse = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetDiffuseFactor(double value)
{
	this->GetFBXSurfaceLambert()->DiffuseFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::SetNormalMap(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->NormalMap = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetBump(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->Bump = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetBumpFactor(double value)
{
	this->GetFBXSurfaceLambert()->BumpFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::SetTransparentColor(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->TransparentColor = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetTransparencyFactor(double value)
{
	this->GetFBXSurfaceLambert()->TransparencyFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::SetDisplacementColor(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->DisplacementColor = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SetDisplacementFactor(double value)
{
	this->GetFBXSurfaceLambert()->DisplacementFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::SetVectorDisplacementColor(double value0, double value1, double value2)
{
	this->GetFBXSurfaceLambert()->VectorDisplacementColor = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfaceLambert::SeVectorDisplacementFactor(double value)
{
	this->GetFBXSurfaceLambert()->VectorDisplacementFactor = value;
}
void ArcManagedFBX::FBXSurfaceLambert::DiffuseConnectSrcObjectHelper(FBXFileTexture^ texture)
{
	this->GetFBXSurfaceLambert()->Diffuse.ConnectSrcObject(texture->GetFBXFileTexture());
}
