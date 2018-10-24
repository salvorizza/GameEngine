#include "System.h"

namespace GameEngine {

	System::System(const SystemData & system_data)
		:m_type(system_data.type)
	{}

	System::~System()
	{}

}
