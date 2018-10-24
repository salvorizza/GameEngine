#ifndef WINDOW_H
#define WINDOW_H

#include<string>


#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "base/System.h"

namespace GameEngine {

	struct WindowData : public SystemData {

		U32 width;
		U32 height;
		std::string title;
		bool vsync;
		bool fullscreen;

		WindowData(U32 _width,U32 _height,const std::string& _title, bool _vsync, bool _fullscreen) 
			: SystemData(SystemType::WINDOW),
			width(_width),
			height(_height),
			title(_title),
			vsync(_vsync),
			fullscreen(_fullscreen)
		{}
	};

	class Window : public System {
	private:
		U32 m_width;
		U32 m_height;
		std::string m_title;
		bool m_vsync;
		bool m_fullscreen;
		GLFWwindow* m_handle;
	private:
		Window(const WindowData& window_data);
	public:
		~Window();
	protected:
		U32 Initialize() override;
		U32 UpdateSystem(const Context& context) override;
	};

}

#endif // !WINDOW_H

