#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Ultra {

	class ULT_API Application
	{
	public:
		Application();
		void Run();
		~Application();
	};

	Application* createApplication();
}

