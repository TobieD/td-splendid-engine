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


int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}