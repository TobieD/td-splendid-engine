#pragma once
#include "../Core/Core.h"

#include "EventType.h"
#include "EventCategory.h"

#include <string>
#include <functional>

namespace Splendid
{
	//Events are currently blocking, meaning if an event occurs it will get dispatched and must be dealt with immediatly
	//It will be better to buffer events and process them together in an update stage

	#define EVENT_CLASS_CATEGORY(category)  virtual int GetCategoryFlags() const override { return category;}

	#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() const override { return EventType::#type; }
									virtual const char* GetName() const override { return #type;}
									virtual EventType GetEventType() const override { return GetStaticType(); }


	class SPLENDID_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;

	};
}