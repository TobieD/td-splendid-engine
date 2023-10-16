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
		if (Splendid::Input::IsKeyPressed(SP_KEY_TAB))
		{
			SP_INFO("Pressed 'Tab'");
		}
	}

	void OnEvent(Splendid::Event& event) override
	{
		
	}
};


class Sandbox : public Splendid::SplendidApplication
{
public:
	Sandbox():
		SplendidApplication(Splendid::WindowConfig("Sandbox", 1600, 800))
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