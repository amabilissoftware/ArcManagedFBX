#pragma once

#include "FBXObject.h"

namespace ArcManagedFBX
{
	public ref class FBXAnimCurveBase : public FBXObject
	{
	public:
			ARC_DEFAULT_CONSTRUCTORS(FBXAnimCurveBase)

			ARC_CLR_CHILD_CAST(FBXAnimCurveBase, FBXObject, FbxAnimCurveBase)

		ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXAnimCurveBase, FbxAnimCurveBase)
	private:
		ARC_CHILD_CAST(NativeObject, FbxAnimCurveBase, FBXAnimCurveBase)
	internal:
	};
}
