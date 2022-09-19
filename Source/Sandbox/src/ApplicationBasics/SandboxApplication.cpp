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
		SP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Splendid::Event& event) override
	{
		SP_INFO("ExampleLayer:: {0}", event);
	}
};


class Sandbox : public Splendid::SplendidApplication
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


Splendid::SplendidApplication* Splendid::CreateApplication()
{
	return new Sandbox();
}