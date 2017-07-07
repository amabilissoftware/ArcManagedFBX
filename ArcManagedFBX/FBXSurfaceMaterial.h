#pragma once

#include "FBXObject.h"

namespace ArcManagedFBX
{
	public ref class FBXSurfaceMaterial : public FBXObject
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXSurfaceMaterial, FBXObject, FbxSurfaceMaterial)
			ARC_DEFAULT_CONSTRUCTORS(FBXSurfaceMaterial)

			ARC_CLR_CHILD_CAST(FBXSurfaceMaterial, FBXObject, FbxSurfaceMaterial)

			void SetShadingModel(String^ value);
			void SetMultiLayer(bool value);

		ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXSurfaceMaterial, FbxSurfaceMaterial)
	private:
		ARC_CHILD_CAST(NativeObject, FbxSurfaceMaterial, FBXSurfaceMaterial)
	internal:
	};
}
