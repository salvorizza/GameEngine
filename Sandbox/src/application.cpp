#include<core/Engine.h>

using namespace GameEngine;

class Game : public Application {
public:
	Game() {

	}
};

int main(int argc, char** argv) {
	Engine& engine = Singleton<Engine>::Instance();
	return engine.Run(new Game());
}