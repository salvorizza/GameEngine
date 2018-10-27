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
		if (m_handle != NULL) {
			glfwDestroyWindow(m_handle);
		}
		glfwTerminate();
	}

	U32 Window::Initialize()
	{
		if (!glfwInit()) {
			//Logger::Log("[WINDOW](Error:Failed to initialize GLFW)");
			return -1;
		}

		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		/*glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);*/

		GLFWmonitor* primary_monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(primary_monitor);

		if (!m_fullscreen) {
			m_handle = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
		}
		else {
			m_width = mode->width;
			m_height = mode->height;
			m_handle = glfwCreateWindow(mode->width, mode->height, m_title.c_str(), primary_monitor, NULL);
		}

		if (m_handle == NULL) {
			return -1;
		}

		U32 centeredX = mode->width / 2 - m_width / 2;
		U32 centeredY = mode->height / 2 - m_height / 2;
		glfwSetWindowPos(m_handle, centeredX, centeredY);


		/*Here we add listeners to window events*/

		glfwShowWindow(m_handle);
		glfwMakeContextCurrent(m_handle);
		if (glewInit() != GLEW_OK) {
			//Logger::Log("[WINDOW](Error:Failed to initialize GLEW)");
			return -1;
		}

		return System::Initialize();
	}

	U32 Window::UpdateSystem(Context& context)
	{
		if (context.pWin == nullptr) {
			context.pWin = this;
		}
		glfwPollEvents();
		glfwSwapBuffers(m_handle);
		return System::UpdateSystem(context);
	}

}