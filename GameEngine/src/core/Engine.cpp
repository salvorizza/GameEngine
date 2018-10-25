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

		/*Here we register all the systems we need*/
		RegisterSystem(new Window({ 640,480, "GameEngine-OpenGL", false,false }));

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
		/*m_pApp =pApp;
		if (m_pApp->Initialize() != 0){
			return -1;
		}*/
		m_engine_state = EngineState::RUNNING;
		Window* pWin = GetSystem<Window>(SystemType::WINDOW);
		if (pWin == nullptr) {
			return -1;
		}
		Context context = { 1,pWin };
		while (!pWin->IsClosed()) {

			pApp->Update(context);

			pApp->Render(context);

			for (auto e : m_systems) {
				if (e.second->UpdateSystem(context) != 0) {
					//Logger::Log("[ENGINE]("Failed to initialize a system")\n");
					return -1;
				}
			}
		}
		return 0;
	}



}
