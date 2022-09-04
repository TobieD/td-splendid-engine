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
	return new Sandbox();
}