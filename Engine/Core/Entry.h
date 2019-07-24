#include "stdafx.h"

#include "Log.h"
#include "Timer.h"
#include "Config.h"
#include "Application.h"
#include "Event/EventBus.h"

using namespace Neon::Application;

extern Application* Neon::Application::CreateApplication();

int main(int argc, char** argv)
{
	Application* app = CreateApplication();

	app->Start();
	app->Run();
	app->Stop();

	delete app;
}

	