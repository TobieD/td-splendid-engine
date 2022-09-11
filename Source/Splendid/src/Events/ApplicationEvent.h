#pragma once

#include "Event.h"
#include "EventType.h"
#include "EventCategory.h"

#include <sstream>

namespace Splendid
{
	class SPLENDID_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_Category(Application)

			std::string ToString() const override
		{
		std:stringstream ss;
			ss << "WindowResizeEvent: [" << m_Width << " ," << m_Height << "]";
			return ss.str();
		}
	private:
		unsigned int m_Width, m_Height;
	};

	class SPLENDID_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_Category(Application)
	};

	class SPLENDID_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_Category(Application)
	};

	class SPLENDID_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_Category(Application)
	};


}