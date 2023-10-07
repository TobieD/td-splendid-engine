#include "splendidpch.h"
#include "Application.h"


#include "Splendid/Core/Log.h"

namespace Splendid
{
	#define BIND_EVENT_FN(x) std::bind(&SplendidApplication::x, this, std::placeholders::_1)

	SplendidApplication* SplendidApplication::s_Instance = nullptr;

	SplendidApplication::SplendidApplication()
	{
		SP_CORE_ASSERT(!s_Instance, "Application already exists!")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	SplendidApplication::~SplendidApplication()
	{
	}

	#pragma region  Application Loops
	void SplendidApplication::Run()
	{
		while (m_Running)
		{
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	void SplendidApplication::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
		
	}

	#pragma endregion

	bool SplendidApplication::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	#pragma region  Layer Stack Management
	void SplendidApplication::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void SplendidApplication::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}
	#pragma endregion
}