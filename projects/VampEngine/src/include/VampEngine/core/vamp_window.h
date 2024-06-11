#pragma once
#include <string>
#include <VampEngine/core/graphics/graphics.h>

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
        GraphicsTypeE graphics;
    };

    class Window
    {
        friend class Application;

        public:
        inline const std::string &GetTitle() const {return m_config.title;}
        inline int GetWidth() const {return m_config.width;}
        inline int GetHeight() const {return m_config.height;}
        inline bool IsRunning() const {return m_isRunning;}
        inline GraphicsContext &GetGraphicsAPI() const {return *m_context;}

        virtual void *GetNativeWindow();

        protected:
        Window(const WindowConfig &config);
        virtual ~Window();

        virtual void Update();

        protected:
        WindowConfig m_config;
        bool m_isRunning;
        GraphicsContext *m_context;


        private:
        static Window *CreateWindow(const WindowConfig &config);

    };
}