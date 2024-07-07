#pragma once

#ifdef HS_PLATFORM_WINDOWS

extern Hoos::Application* Hoos::CreateApplication();

int main(int argc, char** argv)
{
	Hoos::Log::Init();
	HS_CORE_WARN("Initialized Log!");
	int a = 5;
	HS_INFO("Hello! Var={0}", a);


	auto app = Hoos::CreateApplication();
	app->Run();
	delete app;
}

#endif