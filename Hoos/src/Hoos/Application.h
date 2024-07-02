#pragma once

#include "Core.h"

namespace Hoos {
	class HOOS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
