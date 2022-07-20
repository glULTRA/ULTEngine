#include "ultpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "GLFW/glfw3.h"

namespace Ultra {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	void Application::Run()
	{
		while (m_Running) {
			glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	Application::~Application()
	{
		
	}
}