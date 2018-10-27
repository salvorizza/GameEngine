#include<core/Engine.h>

using namespace GameEngine;

class Game : public Application {
public:
	Game()  : Application(ApplicationData()){

	}

	U32 Setup() override {
		return Application::Setup();
	}

	U32 Update(const Context& context)  override{
		return Application::Update(context);
	}

	U32 Render(const Context& context)  override {
		return Application::Render(context);
	}

};

int main(int argc, char** argv) {
	Engine& engine = Singleton<Engine>::Instance();
	return engine.Run(new Game());
}