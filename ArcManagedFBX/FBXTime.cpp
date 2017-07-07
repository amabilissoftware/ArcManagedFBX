#include "Stdafx.h"
#include "FBXTime.h"

using namespace ArcManagedFBX;

FBXTime^ ArcManagedFBX::FBXTime::ConvertTime(FbxTime* instance)
{
	if (instance != nullptr)
		return gcnew FBXTime(instance->GetSecondDouble());

	return gcnew FBXTime(0.0);
}

FbxTime ArcManagedFBX::FBXTime::GenerateTime()
{
	FbxTime outputTime = FbxTime();
	outputTime.SetSecondDouble(this->secondDouble);

	return outputTime;
}

FBXTime::FBXTime(FbxTime time)
{
	this->secondDouble = time.GetSecondDouble();
}

ArcManagedFBX::FBXTime::FBXTime(double secondDouble)
{
	this->secondDouble = secondDouble;
}

String^ ArcManagedFBX::FBXTime::ToString()
{
	return String::Format("SecondDouble:{0}", this->secondDouble);
}

void ArcManagedFBX::FBXTime::SetSecondDouble(double time)
{
	this->secondDouble = time;
}
