#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Splendid::SplendidApplication* Splendid::CreateApplication();

int main(int argc, char** argv) //might need to be wmain for additional information
{
	Splendid::Log::Initialize();
	SP_CORE_WARN("Splendid engine starting");	

	auto app = Splendid::CreateApplication();
	app->Run();
	delete app;
}

#endif // SP_PLATFORM_WINDOWS
