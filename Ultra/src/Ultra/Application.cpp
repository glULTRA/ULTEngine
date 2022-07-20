#include "ultpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"

namespace Ultra {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	void Application::Run()
	{
		/*WindowResizeEvent e(1280, 768);
		if(e.IsInCategory(EventCategoryApplication))
			ULT_TRACE(e.ToString());*/
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}

	Application::~Application()
	{
		
	}
}