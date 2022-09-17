#include "splendidpch.h"
#include "Application.h"

#include "Splendid/Events/ApplicationEvent.h"
#include "Splendid/Core/Log.h"

namespace Splendid
{
	SplendidApplication::SplendidApplication()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
}