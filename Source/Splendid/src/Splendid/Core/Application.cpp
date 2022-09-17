#include "splendidpch.h"
#include "Application.h"

#include "Splendid/Events/ApplicationEvent.h"
#include "Splendid/Core/Log.h"

namespace Splendid
{
	#define BIND_EVENT_FN(x) std::bind(&SplendidApplication::x, this, std::placeholders::_1)

	SplendidApplication::SplendidApplication()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	SplendidApplication::~SplendidApplication()
	{
	}

	void SplendidApplication::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void SplendidApplication::OnEvent(Event& e)
	{
		SP_CORE_INFO("{0}", e);
	}
}