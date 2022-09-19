#pragma once
#include "Splendid\Core\Core.h";
#include "Splendid\Events\Event.h";

namespace Splendid
{
	//Inherit from this to create a custom layer
	//
	class SPLENDID_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		//To implement per layer
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_Name; }

	protected:
		std::string m_Name;
	};
}



