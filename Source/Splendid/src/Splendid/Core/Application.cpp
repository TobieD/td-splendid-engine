#include "Application.h"

#include "Splendid/Events/ApplicationEvent.h"
#include "Splendid/Core/Log.h"

namespace Splendid
{
	SplendidApplication::SplendidApplication()
	{
	}

	SplendidApplication::~SplendidApplication()
	{
	}

	void SplendidApplication::Run()
	{
		WindowResizeEvent e(1280, 720);
		SP_DEBUG(e);

		while (true);
	}
}