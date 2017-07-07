#pragma once

#include "FBXVector.h"
#include "FBXObject.h"

namespace ArcManagedFBX
{
	public value struct FBXQuaternion
	{
	public:

		FBXQuaternion(float64 x, float64 y, float64 z, float64 w);

		virtual String^ ToString() override;

		float64 x, y, z, w;

		FBXVector DecomposeSphericalXYZ();

	private:
	internal:
		FbxQuaternion GenerateQuaternion();

		FBXQuaternion(FbxQuaternion quaternion);

	};
}
