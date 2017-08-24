#include "Stdafx.h"
#include "FBXLine.h"
#include "FBXCamera.h"
#include "FBXSkeleton.h"
#include "FBXShape.h"
#include "FBXLODGroup.h"
#include "FBXLine.h"
#include "FBXBoundary.h"
#include "FBXLight.h"
#include "FBXNode.h"

using namespace ArcManagedFBX;
using namespace ArcManagedFBX::Types;
using namespace ArcManagedFBX::Utility;

using namespace System;
using namespace System::Text;

FBXNode::FBXNode(FbxNode* instance) : FBXObject(instance)
{
}

int FBXNode::AddMaterial(FBXSurfaceMaterial^ material)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->AddMaterial(material->GetFBXSurfaceMaterial());
}

bool FBXNode::RemoveMaterial(FBXSurfaceMaterial^ material)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->RemoveMaterial(material->GetFBXSurfaceMaterial());
}

void FBXNode::AddChild(FBXNode^ node)
{
	ARC_CHECK_AND_THROW(node == nullptr || node->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	this->GetFBXNode()->AddChild(node->GetFBXNode());
}

int32 ArcManagedFBX::FBXNode::GetDefaultNodeAttributeIndex()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->GetDefaultNodeAttributeIndex();
}

int32 ArcManagedFBX::FBXNode::GetNodeAttributeCount()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->GetNodeAttributeCount();
}

FBXNodeAttribute^ ArcManagedFBX::FBXNode::GetNodeAttribute()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	FbxNodeAttribute* attributeInstance = this->GetFBXNode()->GetNodeAttribute();

	// Be sure to cast the value properly into the right clr type otherwise we end up in a scenario where we have to instantiate new objects on the heap.
	switch(this->GetFBXNode()->GetNodeAttribute()->GetAttributeType())
	{
	case FbxNodeAttribute::EType::eLight:
			return FBXNodeAttribute::CreateNodeAttribute<FBXLight^>(attributeInstance);		
		break;

	case FbxNodeAttribute::EType::eBoundary:
			return FBXNodeAttribute::CreateNodeAttribute<FBXBoundary^>(attributeInstance);		
		break;

	case FbxNodeAttribute::EType::eMesh:
			return FBXNodeAttribute::CreateNodeAttribute<FBXMesh^>(attributeInstance);		
		break;

	case FbxNodeAttribute::EType::eSkeleton:
			return FBXNodeAttribute::CreateNodeAttribute<FBXSkeleton^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eCamera:
			return FBXNodeAttribute::CreateNodeAttribute<FBXCamera^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eLine:
			return FBXNodeAttribute::CreateNodeAttribute<FBXLine^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eShape:
			return FBXNodeAttribute::CreateNodeAttribute<FBXShape^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eLODGroup:
			return FBXNodeAttribute::CreateNodeAttribute<FBXLODGroup^>(attributeInstance);
		break;
	}

	return gcnew FBXNodeAttribute(this->GetFBXNode()->GetNodeAttribute());
}

FBXNodeAttribute ^ ArcManagedFBX::FBXNode::GetNodeAttributeByIndex(int32 index)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

		FbxNodeAttribute* attributeInstance = this->GetFBXNode()->GetNodeAttributeByIndex(index);

	// Be sure to cast the value properly into the right clr type otherwise we end up in a scenario where we have to instantiate new objects on the heap.
	switch (this->GetFBXNode()->GetNodeAttribute()->GetAttributeType())
	{
	case FbxNodeAttribute::EType::eLight:
		return FBXNodeAttribute::CreateNodeAttribute<FBXLight^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eBoundary:
		return FBXNodeAttribute::CreateNodeAttribute<FBXBoundary^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eMesh:
		return FBXNodeAttribute::CreateNodeAttribute<FBXMesh^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eSkeleton:
		return FBXNodeAttribute::CreateNodeAttribute<FBXSkeleton^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eCamera:
		return FBXNodeAttribute::CreateNodeAttribute<FBXCamera^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eLine:
		return FBXNodeAttribute::CreateNodeAttribute<FBXLine^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eShape:
		return FBXNodeAttribute::CreateNodeAttribute<FBXShape^>(attributeInstance);
		break;

	case FbxNodeAttribute::EType::eLODGroup:
		return FBXNodeAttribute::CreateNodeAttribute<FBXLODGroup^>(attributeInstance);
		break;
	}

	return gcnew FBXNodeAttribute(this->GetFBXNode()->GetNodeAttribute());
}

FBXNodeAttribute^ ArcManagedFBX::FBXNode::SetNodeAttribute(FBXNodeAttribute^ attribute)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return gcnew FBXNodeAttribute(this->GetFBXNode()->SetNodeAttribute(attribute->GetFBXNodeAttribute()));
}

bool ArcManagedFBX::FBXNode::AddNodeAttribute(FBXNodeAttribute^ attribute)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->AddNodeAttribute(attribute->GetFBXNodeAttribute());
}

ArcManagedFBX::Types::EShadingMode ArcManagedFBX::FBXNode::GetShadingMode()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return (EShadingMode)this->GetFBXNode()->GetShadingMode();
}

void ArcManagedFBX::FBXNode::SetShadingMode(EShadingMode mode)
{
	this->GetFBXNode()->SetShadingMode((FbxNode::EShadingMode)mode);
}

bool ArcManagedFBX::FBXNode::GetVisibility()
{
	return this->GetFBXNode()->GetVisibility();
}

void ArcManagedFBX::FBXNode::SetVisibility(bool isVisible)
{
	this->GetFBXNode()->SetVisibility(isVisible);
}

ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::GetTargetUpVector()
{
	return FBXVector(this->GetFBXNode()->GetTargetUpVector());
}

void ArcManagedFBX::FBXNode::SetTargetUpVector(FBXVector vector)
{
	
}

FBXNode^ ArcManagedFBX::FBXNode::GetTargetUp()
{
	return gcnew FBXNode(this->GetFBXNode()->GetTargetUp());
}

void ArcManagedFBX::FBXNode::SetTargetUp(FBXNode^ pNode)
{
	this->GetFBXNode()->SetTargetUp(pNode->GetFBXNode());
}

ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::GetPostTargetRotation()
{
	return FBXVector(this->GetFBXNode()->GetPostTargetRotation());
}

void ArcManagedFBX::FBXNode::SetRotationOrder(EOrder pRotationOrder)
{
	//this->GetFBXNode()->RotationOrder.Set((fbxsdk::FbxEuler::EOrder)pRotationOrder);
	this->GetFBXNode()->RotationOrder.Set(eEulerZXY);
	//throw gcnew System::NotImplementedException();
}

void ArcManagedFBX::FBXNode::SetPostTargetRotation(FBXVector vector)
{
	// TODO:
}



ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::LclTranslationGet()
{
	return FBXVector(this->GetFBXNode()->LclTranslation.Get());
}

void ArcManagedFBX::FBXNode::LclTranslationSet(FBXVector vector)
{
	this->GetFBXNode()->LclTranslation.Set(FbxVector4(vector.GenerateVector4()));
}

FBXAnimCurveNode ^ ArcManagedFBX::FBXNode::LclTranslationGetCurveNode(FBXAnimLayer ^ animLayer)
{
	return gcnew FBXAnimCurveNode(this->GetFBXNode()->LclTranslation.GetCurveNode(animLayer->GetFBXAnimLayer(), true));
}

FBXAnimCurveNode ^ ArcManagedFBX::FBXNode::LclRotationGetCurveNode(FBXAnimLayer ^ animLayer)
{
	return gcnew FBXAnimCurveNode(this->GetFBXNode()->LclRotation.GetCurveNode(animLayer->GetFBXAnimLayer(), true));
}

FBXAnimCurve ^ ArcManagedFBX::FBXNode::LclTranslationGetCurve(FBXAnimLayer ^ animLayer, String^ channel)
{
	return gcnew FBXAnimCurve(this->GetFBXNode()->LclTranslation.GetCurve(animLayer->GetFBXAnimLayer(), StringHelper::ToNative(channel) , true));
}

FBXAnimCurve ^ ArcManagedFBX::FBXNode::LclRotationGetCurve(FBXAnimLayer ^ animLayer, String^ channel)
{
	return gcnew FBXAnimCurve(this->GetFBXNode()->LclRotation.GetCurve(animLayer->GetFBXAnimLayer(), StringHelper::ToNative(channel), true));
}

ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::LclRotationGet()
{
	return FBXVector(this->GetFBXNode()->LclRotation.Get());
}

void ArcManagedFBX::FBXNode::LclRotationSet(FBXVector vector)
{
	this->GetFBXNode()->LclRotation.Set(FbxVector4(vector.GenerateVector4()));
}

FBXNode^ ArcManagedFBX::FBXNode::GetTarget()
{
	return gcnew FBXNode(this->GetFBXNode()->GetTarget());
}

void ArcManagedFBX::FBXNode::SetTarget(FBXNode^ node)
{
	this->GetFBXNode()->SetTarget(node->GetFBXNode());
}

FBXNode^ ArcManagedFBX::FBXNode::FindChild(String^ name, bool recursive, bool initial)
{
	const char* nameNative = StringHelper::ToNative(name);
	return gcnew FBXNode(this->GetFBXNode()->FindChild(nameNative,recursive,initial));
}

FBXNode^ ArcManagedFBX::FBXNode::GetChild(int32 pIndex)
{
	return gcnew FBXNode(this->GetFBXNode()->GetChild(pIndex));
}

void ArcManagedFBX::FBXNode::RemoveChild(FBXNode^ Node)
{
	this->GetFBXNode()->RemoveChild(Node->GetFBXNode());
}

bool ArcManagedFBX::FBXNode::SetDefaultNodeAttributeIndex(int32 index, FBXStatus^ status)
{
	return this->GetFBXNode()->SetDefaultNodeAttributeIndex(index,status->GetInstance());
}

int32 ArcManagedFBX::FBXNode::GetChildCount(bool recursive)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->GetChildCount();
}
