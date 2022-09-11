#pragma once
#include "Splendid/Core/Core.h"

#include "EventType.h"
#include "EventCategory.h"

namespace Splendid
{
	//Events are currently blocking, meaning if an event occurs it will get dispatched and must be dealt with immediatly
	//It will be better to buffer events and process them together in an update stage
	class SPLENDID_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;		
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		bool Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
			}

			return false;
		}

	private:
		Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}