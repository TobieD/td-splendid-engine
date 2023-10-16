#pragma once
#include <splendidpch.h>

#include "Splendid/Core/Core.h"
#include "Splendid/Events/Event.h"

namespace Splendid
{
	struct WindowConfig {

		std::string Title;
		unsigned int Width, Height;

		WindowConfig(const std::string& title = "Splendid Engine", unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{

		}

	};

	//This is an interface that needs to be implemented per platform
	class SPLENDID_API Window
	{
	public:

		virtual ~Window() = default;

		virtual void OnStartRender() = 0;
		virtual void OnEndRender() = 0;
		virtual void OnUpdate() = 0;

		using EventCallbackFunc = std::function<void(Event&)>;
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;

		static Window* Create(const WindowConfig& config = WindowConfig());

		inline unsigned int GetWidth() { return m_Config.Width; }
		inline unsigned int GetHeight() { return m_Config.Height; }

		virtual void* GetNativeWindow() const = 0;

	protected:
		WindowConfig m_Config;
	};
}