#include "Stdafx.h"
#include "FBXVector2.h"

using namespace ArcManagedFBX;


FBXVector2::FBXVector2(float64 x, float64 y)
{
	this->x = x;
	this->y = y;
}

FBXVector2::FBXVector2(FbxVector2 vector)
{
	this->x = vector.mData[0];
	this->y = vector.mData[1];
}

FBXVector2^ ArcManagedFBX::FBXVector2::ConvertVector2(FbxVector2* instance)
{
	if (instance != nullptr)
		return gcnew FBXVector2(instance->mData[0], instance->mData[1]);

	return gcnew FBXVector2(0.f, 0.f);
}

FbxVector2 ArcManagedFBX::FBXVector2::GenerateVector2()
{
	FbxVector2 outputVector = FbxVector2(this->x, this->y);

	return outputVector;
}

FBXVector2^ ArcManagedFBX::FBXVector2::Zero::get()
{
	return gcnew FBXVector2(0, 0);
}

FBXVector2^ ArcManagedFBX::FBXVector2::One::get()
{
	return gcnew FBXVector2(1.f, 1.f);
}

String^ ArcManagedFBX::FBXVector2::ToString()
{
	return String::Format("X:{0}, Y:{1}", x, y);
}

