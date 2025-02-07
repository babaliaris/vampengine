#include <pch.h>
#include <VampEngine/core/vamp_window.h>
#include <VampEngine/core/memory/memory_manager.h>

#if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
    #include <VampEngine/platform/glfw/glfw_window.h>
#endif

namespace VampEngine
{
    Window::Window(const WindowConfig &config)
    : m_config(config), m_isRunning(false)
    {
        m_context = GraphicsAPI::CreateAPI(config.graphics);
    }


    Window::~Window()
    {
        VAMP_DELETE(m_context);
    }

    Window *Window::CreateWindow(const WindowConfig &config)
    {
        #if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
        if (config.system == WindowSystemE::GLFW)
        {
            return VAMP_NEW(WindowGLFW, config);
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