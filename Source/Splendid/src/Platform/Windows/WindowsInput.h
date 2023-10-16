#pragma once
#include "Splendid/Core/Input.h"

namespace Splendid {
	class WindowsInput: public Input
	{
	protected:		

		virtual bool IsKeyPressedImpl(int keyCode) override;
		virtual bool IsButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;

	};
}