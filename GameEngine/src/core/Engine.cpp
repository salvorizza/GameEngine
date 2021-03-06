#include "Engine.h"

#include"systems/Window.h"

namespace GameEngine {

	Engine::Engine() : Singleton<Engine>(),m_engine_state(EngineState::_INVALID) {
		m_engine_state = EngineState::CONSTRUCTING;
	}

	Engine::~Engine()
	{
		m_engine_state = EngineState::DESTROYING;
	}

	U32 Engine::Initialize(Application* pApp)
	{
		m_engine_state = EngineState::INITIALIZING;

		/*Here we register all the systems we need N.B(THE ORDER IS IMPORTANT)*/
		RegisterSystem(pApp);
		RegisterSystem(new Window({ 640,480, "GameEngine-OpenGL", false,false }));

		//We Initialize all of them
		for (auto e : m_systems) {
			if (e.second->Initialize() != 0) {
				//Logger::Log("[ENGINE]("Failed to initialize a system")\n");
				return -1;
			}
		}

		return 0;
	}



	U32 Engine::Run(Application* pApp)
	{
		if (Initialize(pApp) != 0) {
			return -1;
		}

		if (pApp->Setup() != 0){
			return -1;
		}

		m_engine_state = EngineState::RUNNING;
		Context context = {};
		while (true) {
			for (auto e : m_systems) {
				if (e.second->UpdateSystem(context) != 0) {
					//Logger::Log("[ENGINE]("Failed to initialize a system")\n");
					return -1;
				}
			}
			if (context.pWin == nullptr || context.pWin->IsClosed()) {
				break;
			}
		}
		return 0;
	}



}
