#pragma once

#include "Event.h"
#include "EventType.h"
#include "EventCategory.h"

#include <sstream>

namespace Splendid
{
	class SPLENDID_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(Keyboard | Input)

	protected:
		KeyEvent(int keyCode)
			:m_KeyCode(keyCode) {}

		int m_KeyCode;

	};

	class SPLENDID_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) { }

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;

	};

	class SPLENDID_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode)) { }

		EVENT_CLASS_TYPE(KeyReleased)

		std::string ToString() const override
		{
			std::stringstream ss;	
			ss << "KeyReleasedEvent: " << m_KeyCode;;
			return ss.str();
		}
	};
}