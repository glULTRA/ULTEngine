#include  "ultpch.h"
#include "WindowsInput.h"
#include "Ultra/Application.h"
#include <GLFW/glfw3.h>

namespace Ultra
{
	Input* Input::s_Instance = new WindowsInput();
	bool WindowsInput::IsKeyImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		auto state = glfwGetKey(window, keycode);

		return (state == GLFW_PRESS) || (state == GLFW_REPEAT);
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		auto state = glfwGetMouseButton(window, button);

		return (state == GLFW_PRESS);
	}
	float WindowsInput::GetMouseXImpl()
	{
		auto xpos = GetMousePosition().first;

		return xpos;
	}
	float WindowsInput::GetMouseYImpl()
	{
		auto ypos = GetMousePosition().second;

		return ypos;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return std::pair<float, float>(xpos, ypos);
	}
}