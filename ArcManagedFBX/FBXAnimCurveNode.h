#pragma once

#include "FBXObject.h"

////Standard curve node names
//#define FBXSDK_CURVENODE_TRANSFORM		"Transform"
//#define FBXSDK_CURVENODE_TRANSLATION	"T"
//#define FBXSDK_CURVENODE_ROTATION		"R"
//#define FBXSDK_CURVENODE_SCALING		"S"
//#define FBXSDK_CURVENODE_COMPONENT_X	"X"
//#define FBXSDK_CURVENODE_COMPONENT_Y	"Y"
//#define FBXSDK_CURVENODE_COMPONENT_Z	"Z"
//#define FBXSDK_CURVENODE_COLOR			"Color"
//#define FBXSDK_CURVENODE_COLOR_RED		FBXSDK_CURVENODE_COMPONENT_X
//#define FBXSDK_CURVENODE_COLOR_GREEN	FBXSDK_CURVENODE_COMPONENT_Y
//#define FBXSDK_CURVENODE_COLOR_BLUE		FBXSDK_CURVENODE_COMPONENT_Z

namespace ArcManagedFBX
{
	public ref class FBXAnimCurveNode : public FBXObject
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXAnimCurveNode, FBXObject, FbxAnimCurveNode)
			ARC_DEFAULT_CONSTRUCTORS(FBXAnimCurveNode)

			ARC_CLR_CHILD_CAST(FBXAnimCurveNode, FBXObject, FbxAnimCurveNode)

		ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXAnimCurveNode, FbxAnimCurveNode)
	private:
		ARC_CHILD_CAST(NativeObject, FbxAnimCurveNode, FBXAnimCurveNode)
	internal:
	};
}
