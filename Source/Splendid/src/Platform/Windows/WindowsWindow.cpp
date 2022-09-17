#pragma once
#include <splendidpch.h>
#include "WindowsWindow.h"

namespace Splendid
{
	static uint8_t s_WindowsWindowCount = 0;

	Window* Window::Create(const WindowConfig& config)
	{
		return new WindowsWindow(config);
	}

	WindowsWindow::WindowsWindow(const WindowConfig& config)
	{
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
			int success = glfwInit();
			SP_CORE_ASSERT(success, "Failed to initialize GLFW!");
			SP_CORE_INFO("Done initialize GLFW");
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		glfwSwapInterval(1);

		s_WindowsWindowCount++;
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		s_WindowsWindowCount--;
	}

	void WindowsWindow::OnUpdate()
	{

	}
}