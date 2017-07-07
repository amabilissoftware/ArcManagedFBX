#include "Stdafx.h"
#include "FBXQuaternion.h"

using namespace ArcManagedFBX;


ArcManagedFBX::FBXQuaternion::FBXQuaternion(float64 x, float64 y, float64 z, float64 w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

String ^ ArcManagedFBX::FBXQuaternion::ToString()
{
	return String::Format("X:{0}, Y:{1}, Z:{2}, W:{3}", x, y, z, w);
}

FbxQuaternion ArcManagedFBX::FBXQuaternion::GenerateQuaternion()
{
	return FbxQuaternion(this->x, this->y, this->z, this->w);
}

ArcManagedFBX::FBXQuaternion::FBXQuaternion(FbxQuaternion quaternion)
{
	this->x = quaternion.mData[0];
	this->y = quaternion.mData[1];
	this->z = quaternion.mData[2];
	this->w = quaternion.mData[3];
}

FBXVector ArcManagedFBX::FBXQuaternion::DecomposeSphericalXYZ()
{
	FbxQuaternion fbxQuaternion = FbxQuaternion(this->x, this->y, this->z, this->w);
	return FBXVector(fbxQuaternion.DecomposeSphericalXYZ());
}
