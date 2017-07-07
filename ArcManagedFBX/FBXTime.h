#pragma once

using namespace System;
using namespace System::Text;

namespace ArcManagedFBX
{
	public value struct FBXTime
	{
	public:
		FBXTime::FBXTime(double secondDouble);
		virtual String^ ToString() override;

		void SetSecondDouble(double time);

	private:
		double secondDouble;
	internal:
		FbxTime GenerateTime();

		static FBXTime^ ConvertTime(FbxTime* instance);

		FBXTime(FbxTime time);
	};
}