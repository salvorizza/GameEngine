#include "Application.h"

namespace GameEngine {

	Application::Application(const ApplicationData & application_data)
		: System(application_data)
	{ }

	Application::~Application() {

	}
	U32 Application::Update(const Context & context)
	{
		return U32();
	}
	U32 Application::Render(const Context & context)
	{
		return U32();
	}
	U32 Application::UpdateSystem(const Context & context)
	{
		return System::UpdateSystem(context);
	}
}
