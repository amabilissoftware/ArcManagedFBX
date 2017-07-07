#pragma once

#include "FBXTexture.h"

using namespace ArcManagedFBX::Types;

namespace ArcManagedFBX
{
	public ref class FBXFileTexture : public FBXTexture
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXFileTexture, FBXTexture, FbxFileTexture)
			ARC_DEFAULT_CONSTRUCTORS(FBXFileTexture)

			ARC_CLR_CHILD_CAST(FBXFileTexture, FBXTexture, FbxFileTexture)


			void SetMaterialUse(EMaterialUse materialUse);
			bool SetFileName(String^ fileName);


			ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXFileTexture, FbxFileTexture)


	private:
		ARC_CHILD_CAST(NativeObject, FbxFileTexture, FBXFileTexture)


	};
}
