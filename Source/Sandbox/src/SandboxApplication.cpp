#include <Splendid.h>

class Sandbox : public Splendid::SplendidApplication
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Splendid::SplendidApplication* Splendid::CreateApplication()
{
	//SP_INFO->info("Hello From app");

	return new Sandbox();
}