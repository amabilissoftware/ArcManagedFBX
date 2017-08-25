#pragma once

#include "FBXStatus.h"
#include "FBXNodeAttribute.h"
#include "FBXVector.h"
#include "FBXObject.h"
#include "FBXMesh.h"
#include "FBXManager.h"
#include "FBXSurfaceMaterial.h"
#include "FBXAnimLayer.h"
#include "FBXAnimCurveNode.h"
#include "FBXAnimCurve.h"

using namespace System::Runtime::InteropServices;
using namespace ArcManagedFBX::Layers;

namespace ArcManagedFBX
{
	// The representation of a node within the FBX library
	public ref class FBXNode : public FBXObject
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXNode, FBXObject, FbxNode)

		int AddMaterial(FBXSurfaceMaterial^ material);

		bool RemoveMaterial(FBXSurfaceMaterial^ material);

		int GetMaterialCount();
		FBXSurfaceMaterial^ GetMaterial(int pIndex);

		// Add a child node to this node.
		void AddChild(FBXNode^ Node);

		void RemoveChild(FBXNode^ Node);

		int32 GetChildCount([Optional] bool recursive);

		FBXNode^ GetChild(int32 pIndex);

		FBXNode^ FindChild(String^ name, bool recursive, bool initial);

		void SetTarget(FBXNode^ node);

		FBXNode^ GetTarget();

		void SetPostTargetRotation(FBXVector vector);

		FBXVector GetPostTargetRotation();

		void SetRotationOrder(EOrder pRotationOrder);

		void SetTargetUp(FBXNode^ pNode);

		FBXNode^ GetTargetUp();

		void SetTargetUpVector(FBXVector vector);

		FBXVector GetTargetUpVector();

		void SetVisibility(bool isVisible);

		bool GetVisibility();

		void SetShadingMode(EShadingMode mode);

		EShadingMode GetShadingMode();

		FBXNodeAttribute^ SetNodeAttribute(FBXNodeAttribute^ attribute);

		bool AddNodeAttribute(FBXNodeAttribute^ attribute);

		FBXNodeAttribute^ GetNodeAttribute();

		FBXNodeAttribute^ GetNodeAttributeByIndex(int32 index);

		void LclTranslationSet(FBXVector vector);
		FBXAnimCurveNode^ LclTranslationGetCurveNode(FBXAnimLayer^ animLayer);
		FBXAnimCurveNode^ LclRotationGetCurveNode(FBXAnimLayer^ animLayer);
		FBXAnimCurve^ LclTranslationGetCurve(FBXAnimLayer^ animLayer, String^ channel);
		FBXAnimCurve^ LclRotationGetCurve(FBXAnimLayer^ animLayer, String^ channel);
		void LclRotationSet(FBXVector vector);
		ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::LclTranslationGet();
		ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::LclRotationGet();

			// The attribute count
		int32 GetNodeAttributeCount();
		int32 GetDefaultNodeAttributeIndex();

		// The attribute index.
		bool SetDefaultNodeAttributeIndex(int32 index, FBXStatus^ status);

	internal:
		ARC_CHILD_CAST(NativeObject,FbxNode,FBXNode)
		ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXNode,FbxNode)

	private:

	};
}