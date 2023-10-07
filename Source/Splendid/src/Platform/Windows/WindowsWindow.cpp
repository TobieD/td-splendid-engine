#pragma once
#include <splendidpch.h>
#include "WindowsWindow.h"

#include "Splendid\Events\ApplicationEvent.h"
#include "Splendid\Events\MouseEvent.h"
#include "Splendid\Events\KeyEvent.h"

#include <glad/glad.h>

namespace Splendid
{
	static uint8_t s_WindowsWindowCount = 0;
	static void GLFWErrorCallback(int error, const char* description)
	{
		SP_CORE_ERROR("GLFW error {0}: {1}", error, description);
	}

	Window* Window::Create(const WindowConfig& config)
	{
		
		return new WindowsWindow(config);
	}

	WindowsWindow::WindowsWindow(const WindowConfig& config)
	{
		m_Config = config;
		Initialize(config);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Initialize(const WindowConfig& config)
	{
		m_Data.Title = config.Title;
		m_Data.Width = config.Width;
		m_Data.Height = config.Height;

		SP_CORE_INFO("Creating Window {0} [{1}x{2}]", m_Data.Title, m_Data.Width, m_Data.Height);

		if (s_WindowsWindowCount == 0)
		{
			SP_CORE_INFO("Attempt to initialize GLFW");
			int glfwState = glfwInit();
			SP_CORE_ASSERT(glfwState, "Failed to initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
			SP_CORE_INFO("Done initialize GLFW");
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		int gladState = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SP_CORE_ASSERT(gladState, "Failed to initialize glad!");

		
		glfwSetWindowUserPointer(m_Window, &m_Data);
		s_WindowsWindowCount++;

		glfwSwapInterval(1); //VSync enabled

		//Set up GLFW Callbacks
		SetupCallbacks();
	}

	void WindowsWindow::SetupCallbacks()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				Data& data = *(Data*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.Callback(event);

			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				Data& data = *(Data*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.Callback(event);

			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				Data& data = *(Data*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.Callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.Callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.Callback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				Data& data = *(Data*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.Callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.Callback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				Data& data = *(Data*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.Callback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
			{
				Data& data = *(Data*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)x, (float)y);
				data.Callback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		s_WindowsWindowCount--;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
	}
}