#include <pch.h>
#include <VampEngine/application.h>
#include <VampEngine/debug/logger.h>
#include <VampEngine/debug/assert.h>
#include <VampEngine/core/memory/memory_manager.h>
#include <glad/glad.h>


namespace VampEngine
{
    Application::Application(const ApplicationConfig &config)
    :m_window(nullptr)
    {
        Logger::Init(); //Shared ptrs, no need to destroy.
        MemoryManager::Init();

        WindowConfig windowConfig   = config.GetWindowConfig();
        windowConfig.system         = WindowSystemE::GLFW;
        m_window                    = Window::CreateWindow(windowConfig);

        VAMP_ASSERT(m_window != nullptr);
    }


    Application::~Application()
    {
        VAMP_DELETE(m_window);

        //THIS MUST BE THE LAST TO BE DELETED!
        MemoryManager::Destroy();
    }

    void Application::Run()
    {
        /* Loop until the user closes the window */
        while (m_window->IsRunning())
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            m_window->Update();
        }
    }
}