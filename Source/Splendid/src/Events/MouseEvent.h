#pragma once

#include "Event.h"
#include "EventType.h"
#include "EventCategory.h"

#include <sstream>

namespace Splendid
{
	class SPLENDID_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() const { return m_Button; }

		EVENT_CLASS_Category(Mouse | Input)

		std::string ToString() const override
		{
			std:stringstream ss;
			ss << GetName() << "Event: " << m_Button;
			return ss.str();
		}

	protected:
		MousePressedEvent(int button)
			:m_Button(button) {}

		int m_Button;

	};

	class SPLENDID_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) { }		

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	class SPLENDID_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) { }

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

	class SPLENDID_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EVENT_CLASS_CATEGORY(Mouse | Input)
		EVENT_CLASS_TYPE(MouseMoved)

		std::string ToString() const override
		{
			std:stringstream ss;
			ss << "MouseMovedEvent: [" << m_MouseX << "," << m_MouseY << "]";
			return ss.str();
		}

	private:
		float m_MouseX, m_MouseY;
	};

	class SPLENDID_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y)
			: m_OffsetX(x), m_OffsetY(y) {}

		inline float GetX() const { return m_OffsetX; }
		inline float GetY() const { return m_OffsetY; }

		EVENT_CLASS_CATEGORY(Mouse | Input)
		EVENT_CLASS_TYPE(MouseScrolled)

		std::string ToString() const override
		{
			std:stringstream ss;
			ss << "MouseScrolledEvent: [" << m_OffsetX << "," << m_OffsetY << "]";
			return ss.str();
		}

	private:
		float m_OffsetX, m_OffsetY;
	};
}