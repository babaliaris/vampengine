#include <pch.h>
#include <VampEngine/application.h>
#include <VampEngine/debug/logger.h>
#include <VampEngine/debug/assert.h>
#include <VampEngine/core/file_system.h>
#include <VampEngine/core/memory/memory_manager.h>
#include <VampEngine/core/graphics/graphics.h>


namespace VampEngine
{
    Application::Application(const ApplicationConfig &config)
    :m_window(nullptr)
    {
        FileSystem::Init();
        Logger::Init();
        MemoryManager::Init();

        WindowConfig windowConfig   = config.GetWindowConfig();
        windowConfig.system         = WindowSystemE::GLFW;
        windowConfig.graphics       = GraphicsTypeE::OPENGL;
        m_window                    = Window::CreateWindow(windowConfig);

        VAMP_ASSERT(m_window != nullptr);
    }


    Application::~Application()
    {
        VAMP_DELETE(m_window);

        FileSystem::Destroy();

        //THIS MUST BE THE LAST TO BE DELETED!
        MemoryManager::Destroy();
    }

    void Application::Run()
    {
        m_window->GetGraphicsAPI().SetClearColor(0.5f, 1.0f, 0.5f, 1.0f);
        
        /* Loop until the user closes the window */
        while (m_window->IsRunning())
        {
            /* Render here */
            m_window->GetGraphicsAPI().ClearColorBuffer();

            m_window->Update();
        }
    }
}