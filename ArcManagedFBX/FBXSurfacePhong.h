#pragma once

#include "FBXObject.h"
#include "FBXSurfaceLambert.h"

namespace ArcManagedFBX
{
	public ref class FBXSurfacePhong : public FBXSurfaceLambert
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXSurfacePhong, FBXObject, FbxSurfacePhong)
			ARC_DEFAULT_CONSTRUCTORS(FBXSurfacePhong)

			ARC_CLR_CHILD_CAST(FBXSurfacePhong, FBXSurfaceLambert, FbxSurfacePhong)

			void SetSpecular(double value0, double value1, double value2);
			void SetSpecularFactor(double value);
			void SetShininess(double value);
			void SetReflection(double value0, double value1, double value2);
			void SetReflectionFactor(double value);

			ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXSurfacePhong, FbxSurfacePhong)
	private:
		ARC_CHILD_CAST(NativeObject, FbxSurfacePhong, FBXSurfacePhong)
	};
}
