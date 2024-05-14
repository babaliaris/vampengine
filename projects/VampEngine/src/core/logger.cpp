#include <pch.h>
#include <VampEngine/debug/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace VampEngine
{
    std::shared_ptr<spdlog::logger> Logger::s_engine;
    std::shared_ptr<spdlog::logger> Logger::s_client;

    void Logger::Init()
    {
        s_engine = spdlog::stdout_color_mt("VampEngine");
        s_client = spdlog::stdout_color_mt("Client");

        s_engine->set_pattern("%^[%n] [%D %T] (%l) {%@}: %v%$");
        s_client->set_pattern("%^[%n] [%D %T] (%l) {%@}: %v%$");

        s_engine->set_level(spdlog::level::trace);
        s_client->set_level(spdlog::level::trace);
    }


    void Logger::SetEngineLevel(spdlog::level::level_enum level)
    {
        s_engine->set_level(level);
    }


    void Logger::SetClientLevel(spdlog::level::level_enum level)
    {
        s_client->set_level(level);
    }
}