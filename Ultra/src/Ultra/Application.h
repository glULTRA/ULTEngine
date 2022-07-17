#pragma once

#include "Core.h"

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

