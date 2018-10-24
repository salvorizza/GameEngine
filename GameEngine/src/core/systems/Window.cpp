#include"Window.h"

namespace GameEngine {

	Window::Window(const WindowData& window_data)
		: System(window_data),
		m_width(window_data.width), 
		m_height(window_data.height),
		m_title(window_data.title),
		m_vsync(window_data.vsync),
		m_fullscreen(window_data.fullscreen) 
	{}

	Window::~Window() {

	}

	U32 Window::Initialize()
	{
		if (!glfwInit()) {
			//Logger::Log("[WINDOW](Error:Failed to initialize GLFW)")
			return -1;
		}

		m_handle = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);

		return System::Initialize();
	}

	U32 Window::UpdateSystem(const Context & context)
	{
		glfwPollEvents();
		glfwSwapBuffers(m_handle);
		return System::UpdateSystem(context);
	}

}