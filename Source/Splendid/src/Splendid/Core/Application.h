#pragma once

#include "Core.h"
#include "Splendid/Events/Event.h"
#include "Splendid/Events/ApplicationEvent.h"
#include "Splendid\Layers\Layer.h"
#include "Splendid\Layers\LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	//To be defined in CLIENT
	SplendidApplication* CreateApplication();
}