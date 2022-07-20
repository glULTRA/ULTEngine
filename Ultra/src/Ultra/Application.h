#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Ultra {

	class ULT_API Application
	{
	public:
		Application();
		void Run();
		void OnEvent(Event& e);
		~Application();

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* createApplication();
}

