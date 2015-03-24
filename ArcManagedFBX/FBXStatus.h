#pragma once

using namespace ArcManagedFBX::Types;

namespace ArcManagedFBX
{
	public ref class FBXStatus
	{
	public:
		ARC_DEFAULT_CONSTRUCTORS(FBXStatus)

		void SetCode(StatusCode code);
		String^ GetErrorString();
		void Clear();
		StatusCode GetCode();
		bool Error();

		

	internal:
		FBXStatus(FbxStatus* instance);
		FbxStatus* GetInstance();

	private:
		FbxStatus* m_Instance;

	};
}