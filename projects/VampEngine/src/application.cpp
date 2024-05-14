#include <pch.h>
#include <VampEngine/application.h>
#include <VampEngine/debug/logger.h>

#include <GLFW/glfw3.h>

namespace VampEngine
{
    Application::Application(const ApplicationConfig &config)
    {
        Logger::Init();
    }


    Application::~Application()
    {

    }

    void Application::Run()
    {
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
        {
            int errorCode = glfwGetError(NULL);
            VAMP_ERROR("GLFW [ErrCode: {0}] Failed to be initialized.", errorCode);
        }

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            int errorCode = glfwGetError(NULL);
            VAMP_ERROR("GLFW [ErrCode: {0}] Failed to create the window.", errorCode);
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
    }
}