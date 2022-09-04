#pragma once

#include "Core.h"

namespace Splendid
{
	class SPLENDID_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}