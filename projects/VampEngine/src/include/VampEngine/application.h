#pragma once
#include <string>

namespace VampEngine
{
    struct ApplicationConfig
    {
        std::string window_title;
        int window_width;
        int window_height;
    };

    class Application
    {
        public:
        Application(const ApplicationConfig &config = {"VampEngine", 1024, 1024});
        virtual ~Application();

        void Run();

        private:
    };

    Application *CreateApplication();
}