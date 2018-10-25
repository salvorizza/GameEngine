#ifndef CONTEXT_H
#define CONTEXT_H


#define WIDTH context.pWin->GetWidth();
#define HEIGHT context.pWin->GetHeight();
#define DELTA_TIME context.delta_time;

namespace GameEngine {
	class Window;

	struct Context {
		float delta_time;
		Window* pWin;
	};

}

#endif // !CONTEXT_H
