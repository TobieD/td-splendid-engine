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

		void OnStartRender() override;
		void OnEndRender() override;
		void OnUpdate() override;

		virtual void SetEventCallback(const EventCallbackFunc& callback) { m_Data.Callback = callback; }

		inline GLFWwindow* GetNativeWindow() { return m_Window; }

	private:
		virtual void Initialize(const WindowConfig& config);
		virtual void Shutdown();

		void SetupCallbacks();

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