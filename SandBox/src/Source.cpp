#include <Ultra.h>

class ExampleLayer : public Ultra::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override {
		//ULT_INFO("My update");
	}

	void OnEvent(Ultra::Event& e) override
	{
		//std::cout << e.ToString() << std::endl;
		ULT_WARN("{0}", e.ToString());
	}
};

class SandBox : public Ultra::Application {
public:
	SandBox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Ultra::ImGuiLayer());
	}

	~SandBox() {

	}

};

Ultra::Application* Ultra::createApplication() {
	return new SandBox();
}