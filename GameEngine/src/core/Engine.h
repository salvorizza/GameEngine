#ifndef ENGINE_H
#define ENGINE_H

#include<memory>
#include<iostream>

#include "platform/platform.h"
#include "utils/primitive_types.h"
#include "data_structures/map.h"
#include "systems/base/System.h"
#include "utils/classes/interfaces.h"
#include "utils/classes/singleton.h"
#include "systems/Application.h"

namespace GameEngine {

	enum ENGINE_API EngineState {
		CONSTRUCTING,
		INITIALIZING,
		RUNNING,
		DESTROYING,
		_INVALID
	};

	class ENGINE_API Engine : Singleton<Engine> {
	private:
		EngineState m_engine_state;
		Map<SystemType, System*> m_systems;
		Application* m_pApp;
	protected:
	private:
		U32 Initialize(Application* pApp);

		void RegisterSystem(System* pSys) {
			SystemType sys_type = pSys->GetType();
			if (m_systems.count(sys_type) == 0) {
				m_systems[sys_type] = pSys;
			}
			else {
				//Logger::Log("[ENGINE("Failed to register the system: 'Duplicate key'")]\n");
			}
		}
	public:
		Engine();
		~Engine();

		U32 Run(Application* pApp);

		template<typename T>
		T* GetSystem(SystemType type) {
			T* pSys = nullptr;
			if (m_systems.count(type) != 0) {
				pSys = dynamic_cast<T*>(m_systems[type]);
				if (pSys == nullptr) {
					//Logger:::Log("[ENGINE("Failed to retrieve a system")]\n");
					return nullptr;
				}
			}
			return static_cast<T*>(pSys);
		}

	};

}

#endif // !ENGINE_H

