#pragma once

#include "FBXObject.h"

using namespace ArcManagedFBX::Types;

namespace ArcManagedFBX
{
	public ref class FBXTexture : public FBXObject
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXTexture, FBXObject, FbxTexture)
			ARC_DEFAULT_CONSTRUCTORS(FBXTexture)

			ARC_CLR_CHILD_CAST(FBXTexture, FBXObject, FbxTexture)

			void SetMappingType(EMappingType mappingType);
			void SetTextureUse(ETextureUse textureUse);
			void SetSwapUV(bool swapUV);
			void SetTranslation(double u, double v);
			void SetScale(double u, double v);
			void SetRotation(double u, double v);

		ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXTexture, FbxTexture)
	private:
		ARC_CHILD_CAST(NativeObject, FbxTexture, FBXTexture)
	};
}