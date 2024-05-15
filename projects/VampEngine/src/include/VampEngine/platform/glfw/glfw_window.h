#pragma once
#include <VampEngine/core/vamp_window.h>

struct GLFWwindow;

namespace VampEngine
{
    void GlfwWindowCloseCallback(GLFWwindow *window);
    
    class WindowGLFW : public Window
    {
        friend void GlfwWindowCloseCallback(GLFWwindow *window);

        public:
        WindowGLFW(const WindowConfig &config);
        virtual ~WindowGLFW();

        protected:
        virtual void *GetNativeWindow() override;
        virtual void Update() override;

        private:
        GLFWwindow *m_window;
    };
}