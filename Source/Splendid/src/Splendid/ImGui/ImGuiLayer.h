#pragma once

#include "Splendid/Layers/Layer.h"

#include "Splendid/Events/ApplicationEvent.h"
#include "Splendid/Events/KeyEvent.h"
#include "Splendid/Events/MouseEvent.h"

namespace Splendid
{
	class SPLENDID_API ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnRenderStart();
		void OnRenderEnd();

		void OnUpdate();
		void OnEvent(Splendid::Event& event);

	private:


	private:
		float m_Time = 0.0f;
	};
}



