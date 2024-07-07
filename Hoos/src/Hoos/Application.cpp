#include "hspch.h"
#include "Application.h"

#include "Hoos/Events/ApplicationEvent.h"
#include "Hoos/Log.h"

namespace Hoos {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HS_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HS_TRACE(e);
		}

		while (true);
	}
}