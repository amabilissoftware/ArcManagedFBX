#include "stdafx.h"
#include "FBXMatrix.h"

using namespace ArcManagedFBX;

FBXMatrix::FBXMatrix()
{

}

FBXMatrix::~FBXMatrix()
{

}

FBXMatrix::!FBXMatrix()
{

}

ArcManagedFBX::FBXMatrix::FBXMatrix(float64 m00, float64 m10, float64 m20, float64 m30, float64 m01, float64 m11, float64 m21, float64 m31, float64 m02, float64 m12, float64 m22, float64 m32, float64 m03, float64 m13, float64 m23, float64 m33)
{
	this->m00 = m00;
	this->m10 = m10;
	this->m20 = m20;
	this->m30 = m30;
	this->m01 = m01;
	this->m11 = m11;
	this->m21 = m21;
	this->m31 = m31;
	this->m02 = m02;
	this->m12 = m12;
	this->m22 = m22;
	this->m32 = m32;
	this->m03 = m03;
	this->m13 = m13;
	this->m23 = m23;
	this->m33 = m33;
}


String ^ ArcManagedFBX::FBXMatrix::ToString()
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}

FBXQuaternion ArcManagedFBX::FBXMatrix::GetQuaternion()
{
	FbxMatrix matrix = this->GenerateMatrix();

	FbxVector4 pTranslation;
	FbxQuaternion pRotation;
	FbxVector4 pShearing;
	FbxVector4 pScaling;
	double pSign;
	matrix.GetElements(pTranslation, pRotation, pShearing, pScaling, pSign);

	return FBXQuaternion(pRotation.mData[0], pRotation.mData[1], pRotation.mData[2], pRotation.mData[3]);
}

FbxMatrix ArcManagedFBX::FBXMatrix::GenerateMatrix()
{
	return FbxMatrix(
		this->m00, this->m10, this->m20, this->m30, this->m01, this->m11, this->m21, this->m31, this->m02, this->m12, this->m22, this->m32, this->m03, this->m13, this->m23, this->m33);
}


