#include "splendidpch.h"
#include "WindowsInput.h"

#include <Splendid/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Splendid
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		auto window = static_cast<GLFWwindow*>(SplendidApplication::Get().GetWindow().GetNativeWindow());

		int state = glfwGetKey(window, keyCode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(SplendidApplication::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(SplendidApplication::Get().GetWindow().GetNativeWindow());

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { (float)xPos, (float)yPos };
	}
}
