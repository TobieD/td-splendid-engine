#include <Splendid.h>

class ExampleLayer : public Splendid::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{

	}

	void OnEvent(Splendid::Event& event) override
	{
		
	}
};


class Sandbox : public Splendid::SplendidApplication
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Splendid::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};


Splendid::SplendidApplication* Splendid::CreateApplication()
{
	return new Sandbox();
}