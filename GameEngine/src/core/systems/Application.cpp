#include "Application.h"

namespace GameEngine {

	Application::Application(const ApplicationData& app_data)
		: System(app_data)
	{}

	Application::~Application() 
	{}

	U32 Application::Initialize()
	{
		return System::Initialize();
	}

	U32 Application::UpdateSystem(Context& context)
	{
		Update(context);
		Render(context);
		return System::UpdateSystem(context);
	}
}
