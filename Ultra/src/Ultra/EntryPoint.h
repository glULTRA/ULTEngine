#include "Application.h"
#include  <iostream>

#ifdef ULT_PLATFORM_WINDOWS

extern Ultra::Application* createApplication();

int main(int argc, char** argv) {
	auto app = Ultra::createApplication();
	app->Run();
	delete app;
}

#endif