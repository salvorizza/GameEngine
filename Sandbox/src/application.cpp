#include<core/Engine.h>

using namespace GameEngine;

int main(int argc, char** argv) {
	Engine& engine = Singleton<Engine>::Instance();
	return engine.Run(myApp);
}