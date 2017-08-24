#pragma once

#include "FBXGeometry.h"
#include "FBXVector2.h"
#include "FBXTypes.h"

// The mesh implementation from FBX
namespace ArcManagedFBX
{
	public ref class FBXMesh : public FBXGeometry
	{
	public:
		ARC_FBXSDK_FBXOBJECT_IMPLEMENT(FBXMesh, FBXGeometry, FbxMesh)
		ARC_DEFAULT_CONSTRUCTORS(FBXMesh)

		ARC_CLR_CHILD_CAST(FBXMesh,FBXNodeAttribute,FbxMesh)

		ARC_CLR_CHILD_CAST(FBXMesh,FBXGeometry,FbxMesh)

		void BeginPolygon(int32 pMaterial, int32 pTexture, int32 pGroup, bool pLegacy);

		void AddPolygon(int32 pIndex, int32 pTextureUVIndex);
		
		void EndPolygon();

		bool IsTriangleMesh();

		virtual void Compact();

		void InitTextureUV(int32 Count);

		void InitTextureUVIndices(EMappingMode pMappingMode);

		void AddTextureUV(FBXVector2^ pUV);

		void InitMaterialIndices(EMappingMode pMappingMode);

		ARC_INLINE int32 GetShapeCount();

		ARC_INLINE int32 GetDeformerCount();

		ARC_INLINE void ReservePolygonCount(int32 count);

		ARC_INLINE int32 GetPolygonCount();

		ARC_INLINE int32 GetPolygonVertex(int32 polygonindex, int32 positionInPolygon);

		ARC_INLINE int32 GetPolygonSize(int32 polygonIndex);

		ARC_INLINE int32 GetPolygonGroup(int32 polygonIndex);

		ARC_INLINE void SetPolygonGroup(int32 polygonIndex,int32 group);

		ARC_INLINE int32 GetPolygonVertexCount();

		array<int32>^ GetPolygonVertices();
		
		FBXVector GetPolygonVertexNormal2(int32 polygonIndex, int32 vertexIndex);

		//bool GetPolygonVertexNormals(array<FBXVector>^% normals);

		FBXVector GetPolygonVertexUV2(int32 polygonindex, int32 vertexindex, String^ uvSetName);

		//bool GetPolygonVertexUVs(String^ uvSetName, array<FBXVector>^ uvs, array<int>^ unMappedUVId);

		bool GenerateTangetsData(String^ uvSetName, bool overWrite);

		int RemovePolygon(int32 polygonIndex);

		int32 GetUVLayercount();

		void Reset();

		bool GenerateNormals(bool overview, bool byCtrlPoint, bool cw);

		int32 RemoveBadPolygons();

		int32 GetControlPointsCount();

		ARC_DEFAULT_INTERNAL_CONSTRUCTOR(FBXMesh,FbxMesh)
	private:
		ARC_CHILD_CAST(NativeObject,FbxMesh,FBXMesh)
	};
}