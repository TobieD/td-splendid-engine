#pragma once
#include <splendidpch.h>

#include "Splendid/Core/Core.h"

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

		virtual void OnUpdate() = 0;

		using EventCallbackFunc = std::function<void>(Event&) > ;

		static Window* Create(const WindowConfig& config = WindowConfig());
	};
}