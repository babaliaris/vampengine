#pragma once
#include <string>
#include <VampEngine/core/vamp_window.h>

namespace VampEngine
{
    struct ApplicationConfig
    {
        std::string window_title;
        int window_width;
        int window_height;

        inline WindowConfig GetWindowConfig() const {return {window_title, window_width, window_height};}
    };

    class Application
    {
        public:
        Application(const ApplicationConfig &config = {"VampEngine", 1024, 1024});
        virtual ~Application();

        void Run();

        private:
        Window *m_window;
    };

    Application *CreateApplication();
}