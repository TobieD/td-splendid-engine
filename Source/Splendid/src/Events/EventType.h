#pragma once
#include "../Core/Core.h"

namespace Splendid
{
	//Events are to be implemented in separate event classes
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved
	};
}