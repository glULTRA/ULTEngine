#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Ultra {

	class ULT_API Application
	{
	public:
		Application();
		void Run();
		~Application();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* createApplication();
}

