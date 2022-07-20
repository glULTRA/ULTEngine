#include "ultpch.h"
#include "WindowsWindow.h"
#include "Ultra/Events/ApplicationEvent.h"
#include "Ultra/Events/KeyEvent.h"
#include "Ultra/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Ultra {
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error_code, const char* description) {
		ULT_CORE_ERROR("GLFW Error ({0}): {1}", error_code, description);
	}

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Titile;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
		ULT_CORE_INFO("Creating window {0} ({1}, {2})", props.Titile, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			if(!success) {
				ULT_CORE_ERROR("Could not initialize GLFW !");
			}
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Titile.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			ULT_CORE_ERROR("Could not create a window");
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_Window);

		// OpenGL Loader.
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			ULT_CORE_ERROR("Failed to initialize OpenGL context");
		}

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks.
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				Ultra::WindowResizeEvent e(width, height);
				data.EventCallback(e);
				data.Width = width;
				data.Height = height;
			}
		);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				Ultra::WindowCloseEvent e;
				data.EventCallback(e);
			}
		);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent e(key, 0);
						if (key == 256) {
							glfwSetWindowShouldClose(window, true);
						}
						data.EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent e(key);
						data.EventCallback(e);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent e(key, 1);
						data.EventCallback(e);
						break;
					}
					default:
						break;
				}
			}
		);

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent e(button);
						data.EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent e(button);
						data.EventCallback(e);
						break;
					}
					default:
						break;
				}
			}
		);

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e((float)xoffset, (float)yoffset);
				data.EventCallback(e);
			}
		);

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e(xpos, ypos);
				data.EventCallback(e);
			}
		);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) 
	{
		int interval = enabled ? 1 : 0;
		glfwSwapInterval(interval);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}