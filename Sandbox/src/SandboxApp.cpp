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
		HS_INFO("ExampleLayer::update");
	}

	void OnEvent(Hoos::Event& event) override
	{
		HS_TRACE("{0}", event);
	}
};

class Sandbox : public Hoos::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	
	~Sandbox()
	{

	}
};

Hoos::Application* Hoos::CreateApplication()
{
	return new Sandbox();
}