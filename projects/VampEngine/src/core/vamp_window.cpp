#include <pch.h>
#include <VampEngine/core/vamp_window.h>

#if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
    #include <VampEngine/platform/glfw/glfw_window.h>
#endif

namespace VampEngine
{
    Window::Window(const WindowConfig &config)
    : m_config(config), m_isRunning(false)
    {
    }


    Window::~Window()
    {
    }

    Window *Window::CreateWindow(const WindowConfig &config)
    {
        #if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
        if (config.system == WindowSystemE::GLFW)
        {
            return new WindowGLFW(config);
        }
        #endif

        return nullptr;
    }

    void *Window::GetNativeWindow()
    {
        return nullptr;
    }

    void Window::Update()
    {
    }
}