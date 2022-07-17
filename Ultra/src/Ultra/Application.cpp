#include "Application.h"

namespace Ultra {
	Application::Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 768);
		if(e.GetCategoryFlags() == EventCategoryApplication)
			ULT_TRACE(e.ToString());
		while (true);
	}

	Application::~Application()
	{
	}
}