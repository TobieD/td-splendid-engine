#pragma once
#include <splendidpch.h>

namespace Splendid
{
	//This is an interface that needs to be implemented per platform
	class SPLENDID_API Input
	{
	public:
		static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
		static bool IsButtonPressed(int button) { return s_Instance->IsButtonPressedImpl(button); }
		static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }


	protected:
		virtual bool IsKeyPressedImpl(int keyCode) = 0;
		virtual bool IsButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;

	private:
		static Input* s_Instance;
	};
}