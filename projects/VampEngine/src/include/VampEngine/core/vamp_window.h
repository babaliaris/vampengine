#pragma once
#include <string>

namespace VampEngine
{

    enum class WindowSystemE
    {
        GLFW, WINDOWS, LINUX
    };

    struct WindowConfig
    {
        std::string title;
        int width, height;
        WindowSystemE system;
    };

    class Window
    {
        friend class Application;

        public:
        inline const std::string &GetTitle() const {return m_config.title;}
        inline int GetWidth() const {return m_config.width;}
        inline int GetHeight() const {return m_config.height;}
        inline bool IsRunning() const {return m_isRunning;}

        virtual void *GetNativeWindow();

        protected:
        Window(const WindowConfig &config);
        virtual ~Window();

        virtual void Update();

        protected:
        WindowConfig m_config;
        bool m_isRunning;

        private:
        static Window *CreateWindow(const WindowConfig &config);

    };
}