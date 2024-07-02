#pragma once

#ifdef HS_PLATFORM_WINDOWS

extern Hoos::Application* Hoos::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hoos::CreateApplication();
	app->Run();
	delete app;
}

#endif