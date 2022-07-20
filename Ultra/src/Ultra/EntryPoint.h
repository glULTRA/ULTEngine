#ifdef ULT_PLATFORM_WINDOWS

extern Ultra::Application* createApplication();

int main(int argc, char** argv) 
{
	Ultra::Log::Init();

	ULT_INFO("Hello");
	
	auto app = Ultra::createApplication();
	app->Run();
	delete app;
}

#endif