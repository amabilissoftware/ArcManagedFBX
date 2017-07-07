#pragma once

using namespace System;
using namespace System::Text;

namespace ArcManagedFBX
{
	public value struct FBXVector2
	{
	public:
		FBXVector2(float64 x, float64 y);

		ARC_STATIC_PROPERTY_PUBLICGET(FBXVector2^, Zero)
		ARC_STATIC_PROPERTY_PUBLICGET(FBXVector2^, One)

		virtual String^ ToString() override;

		float64 x, y;

	private:
	internal:
		FbxVector2 GenerateVector2();

		static FBXVector2^ ConvertVector2(FbxVector2* instance);

		FBXVector2(FbxVector2 vector);
	};
}
