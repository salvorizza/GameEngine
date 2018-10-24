#include "Engine.h"

namespace GameEngine {

	Engine::Engine() : Singleton<Engine>(),m_engine_state(EngineState::_INVALID) {
		m_engine_state = EngineState::CONSTRUCTING;
	}

	Engine::~Engine()
	{
		m_engine_state = EngineState::DESTROYING;
	}

	U32 Engine::Initialize()
	{
		m_engine_state = EngineState::INITIALIZING;

		/*Here we register all the systems we need*/

		return 1;
	}



	U32 Engine::Run(Application* pApp)
	{
		if (Initialize() != 0) {
			return -1;
		}
		m_pApp =pApp;
		if (m_pApp->Initialize() != 0){
			return -1;
		}
		m_engine_state = EngineState::RUNNING;

		return 1;
	}



}
