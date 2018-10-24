#ifndef SYSTEM_H
#define SYSTEM_H

#include"../../utils/primitive_types.h"
#include"../../utils/context.h"
#include"../../utils/classes/interfaces.h"

namespace GameEngine {

	enum SystemType {
		WINDOW,
		INPUT,
		APPLICATION,
		INVALID
	};

	struct SystemData {
		SystemType type;

		SystemData(SystemType _type)
			: type(_type)
		{}

	};

	class ENGINE_API System : INonCopyable {
		friend class Engine;
	private:
		SystemType m_type;
	protected:
		System(const SystemData& system_data);
	public:
		virtual ~System();

	protected:
		virtual U32 Initialize() { return 0; }
		virtual U32 UpdateSystem(const Context& context) { return 0; }

		SystemType GetType() const { return m_type; }
	};

}

#endif // !SYSTEM_H
