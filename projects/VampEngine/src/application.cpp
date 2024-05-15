#include <pch.h>
#include <VampEngine/application.h>
#include <VampEngine/debug/logger.h>
#include <VampEngine/debug/assert.h>
#include <glad/glad.h>


namespace VampEngine
{
    Application::Application(const ApplicationConfig &config)
    :m_window(nullptr)
    {
        Logger::Init();

        WindowConfig windowConfig   = config.GetWindowConfig();
        windowConfig.system         = WindowSystemE::GLFW;
        m_window                    = Window::CreateWindow(windowConfig);

        VAMP_ASSERT(m_window != nullptr);
    }


    Application::~Application()
    {
        delete m_window;
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