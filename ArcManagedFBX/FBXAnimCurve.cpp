#include "Stdafx.h"
#include "FBXAnimCurve.h"

using namespace ArcManagedFBX;
using namespace ArcManagedFBX::Types;

FBXAnimCurve::FBXAnimCurve()
{

}

FBXAnimCurve::FBXAnimCurve(FbxAnimCurve* instance) : FBXAnimCurveBase(instance)
{
}

FBXAnimCurve::~FBXAnimCurve()
{

}

FBXAnimCurve::!FBXAnimCurve()
{

}

void ArcManagedFBX::FBXAnimCurve::KeyModifyBegin()
{
	this->GetFBXAnimCurve()->KeyModifyBegin();
}

void ArcManagedFBX::FBXAnimCurve::KeyModifyEnd()
{
	this->GetFBXAnimCurve()->KeyModifyEnd();
}

void ArcManagedFBX::FBXAnimCurve::KeyAddSet(double time, float value) //, EInterpolationType interpolationType)
{
	FbxTime fbxTime;
	fbxTime.SetSecondDouble(time);

	int index = this->GetFBXAnimCurve()->KeyAdd(fbxTime);
	//this->GetFBXAnimCurve()->KeySet(index, fbxTime, value, (FbxAnimCurveDef::EInterpolationType)interpolationType);
	this->GetFBXAnimCurve()->KeySet(index, fbxTime, value);
}

void ArcManagedFBX::FBXAnimCurve::KeySet(int keyIndex, FBXTime^ time, float value) //, EInterpolationType interpolationType)
{
	//this->GetFBXAnimCurve()->KeySet(keyIndex, time->GenerateTime(), value, (FbxAnimCurveDef::EInterpolationType)interpolationType);
	this->GetFBXAnimCurve()->KeySet(keyIndex, time->GenerateTime(), value);
}

int ArcManagedFBX::FBXAnimCurve::KeyAdd(FBXTime^ time)
{
	return this->GetFBXAnimCurve()->KeyAdd(time->GenerateTime());
}
