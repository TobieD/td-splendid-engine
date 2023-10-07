#pragma once

#include "Splendid/Layers/Layer.h"

namespace Splendid
{
	class SPLENDID_API ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Splendid::Event& event);

	private:
		float m_Time = 0.0f;
	};
}



