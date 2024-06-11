#include <pch.h>
#include <VampEngine/platform/glfw/glfw_window.h>
#include <VampEngine/debug/logger.h>
#include <VampEngine/debug/assert.h>
#include <GLFW/glfw3.h>


namespace VampEngine
{
    WindowGLFW::WindowGLFW(const WindowConfig &config)
    : Window(config)
    {
        VAMP_ASSERT_FUNC(glfwInit(), GLFW_TRUE, VAMP_ERROR("GLFW Failed to be initialized!"));

        //Create a windowed mode window and its OpenGL context
        m_window = glfwCreateWindow(config.width, config.height, config.title.c_str(), NULL, NULL);
        if (!m_window)
        {
            glfwTerminate();
            VAMP_ERROR("GLFW Failed to create the window!");
            return;
        }

        m_isRunning = true;

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowCloseCallback(m_window, GlfwWindowCloseCallback);
        
        //Initialize the graphics.
        GraphicsAPI::InitData data;
        data.data = (void *)glfwGetProcAddress;
        m_context->Init(data);
    }


    WindowGLFW::~WindowGLFW()
    {
        glfwTerminate();
    }


    void *WindowGLFW::GetNativeWindow()
    {
        return m_window;
    }



    void WindowGLFW::Update()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }




    void GlfwWindowCloseCallback(GLFWwindow *window)
    {
        WindowGLFW *windowGLFW  = (WindowGLFW *)glfwGetWindowUserPointer(window);
        windowGLFW->m_isRunning = false;
    }
}