#pragma once

#include "Core.h"
#include "Splendid/Events/Event.h"

namespace Splendid
{
	class SPLENDID_API SplendidApplication
	{
		public:
			SplendidApplication();
			virtual ~SplendidApplication();

			void Run();
	};

	//To be defined in CLIENT
	SplendidApplication* CreateApplication();
}