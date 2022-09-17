#pragma once
#include "Splendid/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Splendid
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowConfig& config);
		virtual ~WindowsWindow();

		void OnUpdate() override;

	private:
		virtual void Initialize(const WindowConfig& config);
		virtual void Shutdown();

	private:

		GLFWwindow* m_Window;

		struct Data
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFunc Callback;
		};

		Data m_Data;

	};
}