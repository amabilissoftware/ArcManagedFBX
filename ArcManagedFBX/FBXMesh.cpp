#include "Stdafx.h"
#include "FBXMesh.h"

using namespace ArcManagedFBX;

FBXMesh::FBXMesh()
{

}

FBXMesh::FBXMesh(FbxMesh* instance) : FBXGeometry(instance)
{
}

FBXMesh::~FBXMesh()
{

}

FBXMesh::!FBXMesh()
{

}

void FBXMesh::Compact()
{
	this->GetFBXMesh()->Compact();
}

void FBXMesh::InitTextureUV(int32 count)
{
	this->GetFBXMesh()->InitTextureUV(count);
}

void FBXMesh::InitTextureUVIndices(EMappingMode pMappingMode)
{
	this->GetFBXMesh()->InitTextureUVIndices((fbxsdk::FbxLayerElement::EMappingMode)pMappingMode);
} 

void FBXMesh::InitMaterialIndices(EMappingMode pMappingMode)
{
	this->GetFBXMesh()->InitMaterialIndices((fbxsdk::FbxLayerElement::EMappingMode)pMappingMode);
}


//array<FBXVector>^ ArcManagedFBX::FBXGeometryBase::GetControlPoints(FBXStatus^ status)
//{
//	// Retrieve the total count of control points that exist.
//	int32 controlPointsCount = this->GetFBXGeometryBase()->GetControlPointsCount();
//	array<FBXVector>^ outputVectors = gcnew array<FBXVector>(controlPointsCount);
//
//	// Retrieve the control points
//	FbxVector4* controlPointsHandle = 0;
//
//	if (status != nullptr)
//		controlPointsHandle = this->GetFBXGeometryBase()->GetControlPoints(status->GetInstance());
//	else
//		controlPointsHandle = this->GetFBXGeometryBase()->GetControlPoints(0);
//
//	// Iterate over the control points and store them into the array
//	for (uint32 i = 0; i < (uint32)controlPointsCount; i++)
//		outputVectors[i] = *FBXVector::ConvertVector4(&controlPointsHandle[i]);
//
//	return outputVectors;
//}
//
//void DrawMaterialIndex(KFbxMesh *pMesh) 
//{
//	printf("LayerCount:\n;", pMesh->GetLayerCount());
//	if (pMesh->GetLayerCount() >= 1) {
//		KFbxLayerElementMaterial* pLayerMaterial = pMesh->GetLayer(0)->GetMaterials();
//		KFbxLayerElementArrayTemplate<int> *tmpArray = &pLayerMaterial->GetIndexArray();
//		printf("ArrayCount:\n;", tmpArray->GetCount());
//		for (int i = 0; i < tmpArray->GetCount(); i++) {
//			printf("%d ", tmpArray->GetAt(i));
//		}
//		printf("\n");
//	}
//}

array<int32>^ FBXMesh::GetPolygonMaterialIndices()
{
	array<int32>^ polygonMaterialIndices;

	if (this->GetLayerCount() >= 1) {
		FbxLayerElementMaterial* pLayerMaterial = this->GetFBXMesh()->GetLayer(0)->GetMaterials();
		FbxLayerElementArrayTemplate<int> *tmpArray = &pLayerMaterial->GetIndexArray();

		if (tmpArray->GetCount() > 0)
		{
			polygonMaterialIndices = gcnew array<int32>(tmpArray->GetCount());

			//printf("ArrayCount:\n;", tmpArray->GetCount());
			for (int i = 0; i < tmpArray->GetCount(); i++) {
				polygonMaterialIndices[i] = tmpArray->GetAt(i);
			}
		}
	}

	return polygonMaterialIndices;
}



array<int32>^ FBXMesh::GetPolygonTextureIndices(int32 type)
{
	array<int32>^ polygonTextureIndices;

	if (this->GetLayerCount() >= 1) {
		FbxLayerElementTexture* pLayerTexture = this->GetFBXMesh()->GetLayer(0)->GetTextures((fbxsdk::FbxLayerElement::EType)type); // ::eTextureDiffuse);
		if (pLayerTexture != NULL)
		{
			FbxLayerElementArrayTemplate<int> *tmpArray = &pLayerTexture->GetIndexArray();

			if (tmpArray->GetCount() > 0)
			{
				polygonTextureIndices = gcnew array<int32>(tmpArray->GetCount());

				//printf("ArrayCount:\n;", tmpArray->GetCount());
				for (int i = 0; i < tmpArray->GetCount(); i++) {
					polygonTextureIndices[i] = tmpArray->GetAt(i);
				}
			}
		}
	}

	return polygonTextureIndices;
}

void FBXMesh::AddTextureUV(FBXVector2^ UV)
{
	FbxVector2 generatedVector = UV->GenerateVector2();
	this->GetFBXMesh()->AddTextureUV(generatedVector);
}

void FBXMesh::AddPolygon(int32 pIndex, int32 pTextureUVIndex)
{
	this->GetFBXMesh()->AddPolygon(pIndex,pTextureUVIndex);
}

int32 FBXMesh::GetPolygonCount()
{
	ARC_CHECK_AND_THROW(this->GetFBXMesh() == nullptr,"Native FBX mesh instance is null. Check and try again.")

	return this->GetFBXMesh()->GetPolygonCount();
}

ARC_INLINE int32 ArcManagedFBX::FBXMesh::GetPolygonSize(int32 polygonIndex)
{
	ARC_CHECK_AND_THROW(this->GetFBXMesh() == nullptr,"Native FBX mesh instance is null. Check and try again.")

	return this->GetFBXMesh()->GetPolygonSize(polygonIndex);
}

ARC_INLINE int32 ArcManagedFBX::FBXMesh::GetPolygonGroup(int32 polygonIndex)
{
	ARC_CHECK_AND_THROW(this->GetFBXMesh() == nullptr,"Native FBX mesh instance is null. Check and try again.")

	return this->GetFBXMesh()->GetPolygonGroup(polygonIndex);
}

ARC_INLINE void ArcManagedFBX::FBXMesh::SetPolygonGroup(int32 polygonIndex,int32 group)
{
	ARC_CHECK_AND_THROW(this->GetFBXMesh() == nullptr,"Native FBX mesh instance is null. Check and try again.")

	this->GetFBXMesh()->SetPolygonGroup(polygonIndex,group);
}

FBXVector ArcManagedFBX::FBXMesh::GetPolygonVertexNormal2(int32 polygonIndex, int32 vertexIndex)
{
	FbxVector4 fbxNormal;
	bool result = this->GetFBXMesh()->GetPolygonVertexNormal(polygonIndex, vertexIndex, fbxNormal);

	return FBXVector(fbxNormal);
}

FBXVector ArcManagedFBX::FBXMesh::GetPolygonVertexUV2(int32 polygonindex, int32 vertexindex, String^ uvSetName)
{
	FbxVector2 fbxUV;
	bool unMapped;
	const char* nativeName = StringHelper::ToNative(uvSetName);
	bool result = this->GetFBXMesh()->GetPolygonVertexUV(polygonindex, vertexindex, nativeName, fbxUV, unMapped);
	return FBXVector(fbxUV.mData[0], fbxUV.mData[1], fbxUV.mData[2], fbxUV.mData[3]); // FBXVector(UV);
}

void ArcManagedFBX::FBXMesh::EndPolygon()
{
	this->GetFBXMesh()->EndPolygon();
}


void ArcManagedFBX::FBXMesh::BeginPolygon(int32 pMaterial, int32 pTexture, int32 pGroup, bool pLegacy)
{
	this->GetFBXMesh()->BeginPolygon(pMaterial,pTexture,pGroup,pLegacy);
}

array<int>^ ArcManagedFBX::FBXMesh::GetPolygonVertices()
{
	int32 vertexCount = this->GetFBXMesh()->GetPolygonVertexCount();

	array<int>^ vertexOutput = gcnew array<int>(vertexCount);
	int* vertices = this->GetFBXMesh()->GetPolygonVertices();

	if (vertices != nullptr)
	{
		for(int32 i = 0; i < vertexCount; i++)
			vertexOutput[i] = vertices[i];
	}

	return vertexOutput;
}

//bool ArcManagedFBX::FBXMesh::GetPolygonVertexUVs(String^ uvSetName, array<FBXVector>^ uvs, array<int>^ unMappedUVId)
//{
//	return false;
//}
//
//bool ArcManagedFBX::FBXMesh::GetPolygonVertexUV(int32 polygonindex, int32 vertexindex, String^ uvSetName, FBXVector uv, bool^ unmapped)
//{
//	return false;
//}

// This is going to require some work as we convert between an fbx array and a CLI array that is to be used for returning to the consumer.
//bool ArcManagedFBX::FBXMesh::GetPolygonVertexNormals(array<FBXVector>^% normals)
//{	
//	// TODO: Implement this
//	return false;
//}


int ArcManagedFBX::FBXMesh::RemoveBadPolygons()
{
	return this->GetFBXMesh()->RemoveBadPolygons();
}

bool ArcManagedFBX::FBXMesh::GenerateNormals(bool overview, bool byCtrlPoint, bool cw)
{
	return this->GetFBXMesh()->GenerateNormals(overview,byCtrlPoint,cw);
}

void ArcManagedFBX::FBXMesh::Reset()
{
	return this->GetFBXMesh()->Reset();
}

int32 ArcManagedFBX::FBXMesh::GetUVLayercount()
{
	return this->GetFBXMesh()->GetUVLayerCount();
}

int ArcManagedFBX::FBXMesh::RemovePolygon(int32 polygonIndex)
{
	return this->GetFBXMesh()->RemovePolygon(polygonIndex);
}

ARC_INLINE void ArcManagedFBX::FBXMesh::ReservePolygonCount(int count)
{
	return this->GetFBXMesh()->ReservePolygonCount(count);
}

bool ArcManagedFBX::FBXMesh::IsTriangleMesh()
{
	return this->GetFBXMesh()->IsTriangleMesh();
}

bool ArcManagedFBX::FBXMesh::GenerateTangetsData(String^ uvSetName, bool overWrite)
{
	return false;
}

ARC_INLINE int32 ArcManagedFBX::FBXMesh::GetPolygonVertexCount()
{
	return this->GetFBXMesh()->GetPolygonVertexCount();
}

ARC_INLINE int32 ArcManagedFBX::FBXMesh::GetPolygonVertex(int32 polygonindex, int32 positionInPolygon)
{
	return this->GetFBXMesh()->GetPolygonVertex(polygonindex,positionInPolygon);
}

int32 ArcManagedFBX::FBXMesh::GetControlPointsCount()
{
	return this->GetFBXMesh()->GetControlPointsCount();
}

int32 ArcManagedFBX::FBXMesh::GetShapeCount()
{
	return GetFBXMesh()->GetShapeCount();
}

int32 ArcManagedFBX::FBXMesh::GetDeformerCount()
{
	return GetFBXMesh()->GetDeformerCount();
}


//void DisplayMaterial(FbxGeometry* pGeometry)
//{
//	int lMaterialCount = 0;
//	FbxNode* lNode = NULL;
//	if (pGeometry) {
//		lNode = pGeometry->GetNode();
//		if (lNode)
//			lMaterialCount = lNode->GetMaterialCount();
//	}
//
//	if (lMaterialCount > 0)
//	{
//		FbxPropertyT<FbxDouble3> lKFbxDouble3;
//		FbxPropertyT<FbxDouble> lKFbxDouble1;
//		FbxColor theColor;
//
//		for (int lCount = 0; lCount < lMaterialCount; lCount++)
//		{
//			DisplayInt("        Material ", lCount);
//
//			FbxSurfaceMaterial *lMaterial = lNode->GetMaterial(lCount);
//
//			DisplayString("            Name: \"", (char *)lMaterial->GetName(), "\"");
//
//			//Get the implementation to see if it's a hardware shader.
//			const FbxImplementation* lImplementation = GetImplementation(lMaterial, FBXSDK_IMPLEMENTATION_HLSL);
//			FbxString lImplemenationType = "HLSL";
//			if (!lImplementation)
//			{
//				lImplementation = GetImplementation(lMaterial, FBXSDK_IMPLEMENTATION_CGFX);
//				lImplemenationType = "CGFX";
//			}
//			if (lImplementation)
//			{
//				//Now we have a hardware shader, let's read it
//				FBXSDK_printf("            Hardware Shader Type: %s\n", lImplemenationType.Buffer());
//				const FbxBindingTable* lRootTable = lImplementation->GetRootTable();
//				FbxString lFileName = lRootTable->DescAbsoluteURL.Get();
//				FbxString lTechniqueName = lRootTable->DescTAG.Get();
//
//
//				const FbxBindingTable* lTable = lImplementation->GetRootTable();
//				size_t lEntryNum = lTable->GetEntryCount();
//
//				for (int i = 0; i <(int)lEntryNum; ++i)
//				{
//					const FbxBindingTableEntry& lEntry = lTable->GetEntry(i);
//					const char* lEntrySrcType = lEntry.GetEntryType(true);
//					FbxProperty lFbxProp;
//
//
//					FbxString lTest = lEntry.GetSource();
//					FBXSDK_printf("            Entry: %s\n", lTest.Buffer());
//
//
//					if (strcmp(FbxPropertyEntryView::sEntryType, lEntrySrcType) == 0)
//					{
//						lFbxProp = lMaterial->FindPropertyHierarchical(lEntry.GetSource());
//						if (!lFbxProp.IsValid())
//						{
//							lFbxProp = lMaterial->RootProperty.FindHierarchical(lEntry.GetSource());
//						}
//
//
//					}
//					else if (strcmp(FbxConstantEntryView::sEntryType, lEntrySrcType) == 0)
//					{
//						lFbxProp = lImplementation->GetConstants().FindHierarchical(lEntry.GetSource());
//					}
//					if (lFbxProp.IsValid())
//					{
//						if (lFbxProp.GetSrcObjectCount<FbxTexture>() > 0)
//						{
//							//do what you want with the textures
//							for (int j = 0; j<lFbxProp.GetSrcObjectCount<FbxFileTexture>(); ++j)
//							{
//								FbxFileTexture *lTex = lFbxProp.GetSrcObject<FbxFileTexture>(j);
//								FBXSDK_printf("           File Texture: %s\n", lTex->GetFileName());
//							}
//							for (int j = 0; j<lFbxProp.GetSrcObjectCount<FbxLayeredTexture>(); ++j)
//							{
//								FbxLayeredTexture *lTex = lFbxProp.GetSrcObject<FbxLayeredTexture>(j);
//								FBXSDK_printf("        Layered Texture: %s\n", lTex->GetName());
//							}
//							for (int j = 0; j<lFbxProp.GetSrcObjectCount<FbxProceduralTexture>(); ++j)
//							{
//								FbxProceduralTexture *lTex = lFbxProp.GetSrcObject<FbxProceduralTexture>(j);
//								FBXSDK_printf("     Procedural Texture: %s\n", lTex->GetName());
//							}
//						}
//						else
//						{
//							FbxDataType lFbxType = lFbxProp.GetPropertyDataType();
//							FbxString blah = lFbxType.GetName();
//							if (FbxBoolDT == lFbxType)
//							{
//								DisplayBool("                Bool: ", lFbxProp.Get<FbxBool>());
//							}
//							else if (FbxIntDT == lFbxType || FbxEnumDT == lFbxType)
//							{
//								DisplayInt("                Int: ", lFbxProp.Get<FbxInt>());
//							}
//							else if (FbxFloatDT == lFbxType)
//							{
//								DisplayDouble("                Float: ", lFbxProp.Get<FbxFloat>());
//
//							}
//							else if (FbxDoubleDT == lFbxType)
//							{
//								DisplayDouble("                Double: ", lFbxProp.Get<FbxDouble>());
//							}
//							else if (FbxStringDT == lFbxType
//								|| FbxUrlDT == lFbxType
//								|| FbxXRefUrlDT == lFbxType)
//							{
//								DisplayString("                String: ", lFbxProp.Get<FbxString>().Buffer());
//							}
//							else if (FbxDouble2DT == lFbxType)
//							{
//								FbxDouble2 lDouble2 = lFbxProp.Get<FbxDouble2>();
//								FbxVector2 lVect;
//								lVect[0] = lDouble2[0];
//								lVect[1] = lDouble2[1];
//
//								Display2DVector("                2D vector: ", lVect);
//							}
//							else if (FbxDouble3DT == lFbxType || FbxColor3DT == lFbxType)
//							{
//								FbxDouble3 lDouble3 = lFbxProp.Get<FbxDouble3>();
//
//
//								FbxVector4 lVect;
//								lVect[0] = lDouble3[0];
//								lVect[1] = lDouble3[1];
//								lVect[2] = lDouble3[2];
//								Display3DVector("                3D vector: ", lVect);
//							}
//
//							else if (FbxDouble4DT == lFbxType || FbxColor4DT == lFbxType)
//							{
//								FbxDouble4 lDouble4 = lFbxProp.Get<FbxDouble4>();
//								FbxVector4 lVect;
//								lVect[0] = lDouble4[0];
//								lVect[1] = lDouble4[1];
//								lVect[2] = lDouble4[2];
//								lVect[3] = lDouble4[3];
//								Display4DVector("                4D vector: ", lVect);
//							}
//							else if (FbxDouble4x4DT == lFbxType)
//							{
//								FbxDouble4x4 lDouble44 = lFbxProp.Get<FbxDouble4x4>();
//								for (int j = 0; j<4; ++j)
//								{
//
//									FbxVector4 lVect;
//									lVect[0] = lDouble44[j][0];
//									lVect[1] = lDouble44[j][1];
//									lVect[2] = lDouble44[j][2];
//									lVect[3] = lDouble44[j][3];
//									Display4DVector("                4x4D vector: ", lVect);
//								}
//
//							}
//						}
//
//					}
//				}
//			}
//			else if (lMaterial->GetClassId().Is(FbxSurfacePhong::ClassId))
//			{
//				// We found a Phong material.  Display its properties.
//
//				// Display the Ambient Color
//				lKFbxDouble3 = ((FbxSurfacePhong *)lMaterial)->Ambient;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Ambient: ", theColor);
//
//				// Display the Diffuse Color
//				lKFbxDouble3 = ((FbxSurfacePhong *)lMaterial)->Diffuse;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Diffuse: ", theColor);
//
//				// Display the Specular Color (unique to Phong materials)
//				lKFbxDouble3 = ((FbxSurfacePhong *)lMaterial)->Specular;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Specular: ", theColor);
//
//				// Display the Emissive Color
//				lKFbxDouble3 = ((FbxSurfacePhong *)lMaterial)->Emissive;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Emissive: ", theColor);
//
//				//Opacity is Transparency factor now
//				lKFbxDouble1 = ((FbxSurfacePhong *)lMaterial)->TransparencyFactor;
//				DisplayDouble("            Opacity: ", 1.0 - lKFbxDouble1.Get());
//
//				// Display the Shininess
//				lKFbxDouble1 = ((FbxSurfacePhong *)lMaterial)->Shininess;
//				DisplayDouble("            Shininess: ", lKFbxDouble1.Get());
//
//				// Display the Reflectivity
//				lKFbxDouble1 = ((FbxSurfacePhong *)lMaterial)->ReflectionFactor;
//				DisplayDouble("            Reflectivity: ", lKFbxDouble1.Get());
//			}
//			else if (lMaterial->GetClassId().Is(FbxSurfaceLambert::ClassId))
//			{
//				// We found a Lambert material. Display its properties.
//				// Display the Ambient Color
//				lKFbxDouble3 = ((FbxSurfaceLambert *)lMaterial)->Ambient;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Ambient: ", theColor);
//
//				// Display the Diffuse Color
//				lKFbxDouble3 = ((FbxSurfaceLambert *)lMaterial)->Diffuse;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Diffuse: ", theColor);
//
//				// Display the Emissive
//				lKFbxDouble3 = ((FbxSurfaceLambert *)lMaterial)->Emissive;
//				theColor.Set(lKFbxDouble3.Get()[0], lKFbxDouble3.Get()[1], lKFbxDouble3.Get()[2]);
//				DisplayColor("            Emissive: ", theColor);
//
//				// Display the Opacity
//				lKFbxDouble1 = ((FbxSurfaceLambert *)lMaterial)->TransparencyFactor;
//				DisplayDouble("            Opacity: ", 1.0 - lKFbxDouble1.Get());
//			}
//			else
//				DisplayString("Unknown type of Material");
//
//			FbxPropertyT<FbxString> lString;
//			lString = lMaterial->ShadingModel;
//			DisplayString("            Shading Model: ", lString.Get().Buffer());
//			DisplayString("");
//		}
//	}
//}
