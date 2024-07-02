#include <Hoos.h>

class Sandbox : public Hoos::Application
{
public:
	Sandbox()
	{

	}
	
	~Sandbox()
	{

	}
};

Hoos::Application* Hoos::CreateApplication()
{
	return new Sandbox();
}