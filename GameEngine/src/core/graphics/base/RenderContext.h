#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include "../../platform/platform.h"

namespace GameEngine {

	class ENGINE_API RenderContext {
		friend class Engine;
	protected:
		RenderContext();
	public:
		virtual ~RenderContext();

		virtual void RenderTriangle();
	};

}

#endif // !RENDER_CONTEXT_H
