#include "Stdafx.h"
#include "FBXCollection.h"

using namespace ArcManagedFBX;

FBXCollection::FBXCollection()
{

}

FBXCollection::~FBXCollection()
{

}

FBXCollection::!FBXCollection()
{

}

bool ArcManagedFBX::FBXCollection::AddMember(FBXObject ^ pMember)
{
	return this->m_NativeObject->ConnectSrcObject(pMember->GetFBXObject());
}

FBXCollection::FBXCollection(FbxCollection* instance) : FBXObject(instance)
{
}