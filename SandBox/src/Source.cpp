#include <Ultra.h>

class SandBox : public Ultra::Application {
public:
	SandBox() {

	}

	~SandBox() {

	}

};

Ultra::Application* Ultra::createApplication() {
	return new SandBox();
}