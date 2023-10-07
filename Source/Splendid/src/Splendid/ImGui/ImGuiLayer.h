#pragma once

#include "Splendid/Layers/Layer.h"

namespace Splendid
{
	class ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Splendid::Event& event);

	private:

	};
}



