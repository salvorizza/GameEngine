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

	class ENGINE_API Application : public System{
		friend class Engine;
	private:
	public:
		Application(const ApplicationData& app_data);
		virtual ~Application();

		virtual U32 Setup() {
			return 0;
		}

		virtual U32 Update(const Context& context) {
			return 0;
		}

		virtual U32 Render(const Context& context) {
			return 0;
		}
	protected:

		U32 Initialize() override;
		U32 UpdateSystem(Context& context) override;

	};

}

#endif // !APPLICATION_H
