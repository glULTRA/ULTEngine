#pragma once

#include "Ultra/Input.h"

namespace Ultra 
{
	class ULT_API WindowsInput : public Input
	{
	public:
		
	protected:
		// Inherited via Input
		virtual bool IsKeyImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}