#pragma once

#include "FBXAnimCurveBase.h"
#include "FBXAnimCurveKeyBase.h"
#include "FBXTime.h"

using namespace ArcManagedFBX::Types;

namespace ArcManagedFBX
{
	public ref class FBXAnimCurve : public FBXAnimCurveBase
	{
	public:
			ARC_DEFAULT_CONSTRUCTORS(FBXAnimCurve)

			ARC_CLR_CHILD_CAST(FBXAnimCurve, FBXObject, FbxAnimCurve)

			void KeyModifyBegin();
			void KeyModifyEnd();
			void KeySet(int pKeyIndex, FBXTime^ pTime, float pValue); //, EInterpolationType interpolationType);
			int KeyAdd(FBXTime^ pTime);
			void KeyAddSet(double time, float value); //, EInterpolationType interpolationType);

			ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXAnimCurve, FbxAnimCurve)
	private:
		ARC_CHILD_CAST(NativeObject, FbxAnimCurve, FBXAnimCurve)
	internal:
	};
}