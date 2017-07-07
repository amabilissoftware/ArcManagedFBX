#pragma once

#include "FBXObject.h"
#include "FBXSurfaceMaterial.h"
#include "FBXVector.h"
#include "FBXFileTexture.h"

namespace ArcManagedFBX
{
	public ref class FBXSurfaceLambert : public FBXSurfaceMaterial
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXSurfaceLambert, FBXObject, FbxSurfaceLambert)
			ARC_DEFAULT_CONSTRUCTORS(FBXSurfaceLambert)

			ARC_CLR_CHILD_CAST(FBXSurfaceLambert, FBXSurfaceMaterial, FbxSurfaceLambert)

			void SetEmissive(double value0, double value1, double value2);
			void SetEmissiveFactor(double value);
			void SetAmbient(double value0, double value1, double value2);
			void SetAmbientFactor(double value);
			void SetDiffuse(double value0, double value1, double value2);
			void SetDiffuseFactor(double value);
			void SetNormalMap(double value0, double value1, double value2);
			void SetBump(double value0, double value1, double value2);
			void SetBumpFactor(double value);
			void SetTransparentColor(double value0, double value1, double value2);
			void SetTransparencyFactor(double value);
			void SetDisplacementColor(double value0, double value1, double value2);
			void SetDisplacementFactor(double value);
			void SetVectorDisplacementColor(double value0, double value1, double value2);
			void SeVectorDisplacementFactor(double value);
			void DiffuseConnectSrcObjectHelper(FBXFileTexture^ texture);

			ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXSurfaceLambert, FbxSurfaceLambert)
	private:
		ARC_CHILD_CAST(NativeObject, FbxSurfaceLambert, FBXSurfaceLambert)
	};
}
