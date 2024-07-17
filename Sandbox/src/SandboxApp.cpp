#include <Hoos.h>

class ExampleLayer : public Hoos::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Hoos::Input::IsKeyPressed(HS_KEY_TAB))
			HS_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Hoos::Event& event) override
	{
		if (event.GetEventType() == Hoos::EventType::KeyPressed)
		{
			Hoos::KeyPressedEvent& e = (Hoos::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HS_KEY_TAB)
				HS_TRACE("Tab key is pressed (event)!");

			HS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Hoos::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hoos::ImGuiLayer());
	}
	
	~Sandbox()
	{

	}
};

Hoos::Application* Hoos::CreateApplication()
{
	return new Sandbox();
}