#ifndef APPLICATION_H
#define APPLICATION_H

#include"../platform/platform.h"
#include"base/System.h"

namespace GameEngine {

	struct ApplicationData : public SystemData {

		/*Here you can specify all the things you need for the application to run;
		title,renderer,size etc...*/

		ApplicationData()
			: SystemData(SystemType::APPLICATION)
		{}

	};

	class ENGINE_API Application{
		friend class Engine;
	private:
	public:
		Application();
		virtual ~Application();

		U32 Update(const Context& context);
		U32 Render(const Context& context);
	};

}

#endif // !APPLICATION_H
