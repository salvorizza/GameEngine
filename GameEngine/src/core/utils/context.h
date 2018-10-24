#ifndef CONTEXT_H
#define CONTEXT_H

class Window;

#define WIDTH context.pWin->GetWidth();
#define HEIGHT context.pWin->GetHeight();
#define DELTA_TIME context.delta_time;

namespace GameEngine {

	struct Context {
		float delta_time;
		Window* pWin;
	};

}

#endif // !CONTEXT_H
