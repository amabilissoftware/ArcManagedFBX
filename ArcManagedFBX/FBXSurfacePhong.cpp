#include "Stdafx.h"
#include "FBXSurfacePhong.h"

using namespace ArcManagedFBX;

FBXSurfacePhong::FBXSurfacePhong()
{

}

FBXSurfacePhong::FBXSurfacePhong(FbxSurfacePhong* instance) : FBXSurfaceLambert(instance)
{
}

FBXSurfacePhong::~FBXSurfacePhong()
{

}

FBXSurfacePhong::!FBXSurfacePhong()
{

}

void ArcManagedFBX::FBXSurfacePhong::SetSpecular(double value0, double value1, double value2)
{
	this->GetFBXSurfacePhong()->Specular = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfacePhong::SetSpecularFactor(double value)
{
	this->GetFBXSurfacePhong()->SpecularFactor = value;
}
void ArcManagedFBX::FBXSurfacePhong::SetShininess(double value)
{
	this->GetFBXSurfacePhong()->Shininess = value;
}
void ArcManagedFBX::FBXSurfacePhong::SetReflection(double value0, double value1, double value2)
{
	this->GetFBXSurfacePhong()->Reflection = FbxDouble3(value0, value1, value2);
}
void ArcManagedFBX::FBXSurfacePhong::SetReflectionFactor(double value)
{
	this->GetFBXSurfacePhong()->ReflectionFactor = value;
}
