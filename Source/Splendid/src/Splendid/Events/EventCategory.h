#pragma once
#include "../Core/Core.h"

namespace Splendid
{
	//can be used to filter out certain events
	enum EventCategory
	{
		None = 0,
		Application = BIT(0),
		Input = BIT(1),
		Keyboard = BIT(2),
		Mouse = BIT(3),
		MouseButton = BIT(4)
	};

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
}