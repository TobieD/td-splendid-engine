#include <Splendid.h>

class Sandbox : public Splendid::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Splendid::Application* Splendid::CreateApplication()
{
	SP_INFO->info("Hello From app");

	return new Sandbox();
}