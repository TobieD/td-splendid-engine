#pragma once

#include "Core.h"
#include "Splendid/Events/Event.h"
#include "Splendid/Events/ApplicationEvent.h"
#include "Window.h"

namespace Splendid
{
	class SPLENDID_API SplendidApplication
	{
	public:
		SplendidApplication();
		virtual ~SplendidApplication();

		void Run();

		void OnEvent(Event& e);

	private:

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in CLIENT
	SplendidApplication* CreateApplication();
}