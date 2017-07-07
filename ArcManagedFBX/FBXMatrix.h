#pragma once

#include "FBXVector.h"
#include "FBXObject.h"
#include "FBXQuaternion.h"

namespace ArcManagedFBX
{
	public ref class FBXMatrix
	{
	public:

		ARC_DEFAULT_CONSTRUCTORS(FBXMatrix)

			FBXMatrix(float64 m00, float64 m10, float64 m20, float64 m30,
				float64 m01, float64 m11, float64 m21, float64 m31,
				float64 m02, float64 m12, float64 m22, float64 m32,
				float64 m03, float64 m13, float64 m23, float64 m33);

		virtual String^ ToString() override;

		float64 m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33;
		FBXQuaternion GetQuaternion();

	private:
	internal:
		FbxMatrix GenerateMatrix();

	};
}

