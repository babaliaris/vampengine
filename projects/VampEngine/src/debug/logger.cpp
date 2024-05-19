#include <pch.h>
#include <string>
#include <sstream>
#include <VampEngine/debug/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <VampEngine/core/file_system.h>

namespace VampEngine
{
    std::shared_ptr<spdlog::logger> Logger::s_memory;
    std::shared_ptr<spdlog::logger> Logger::s_engine;
    std::shared_ptr<spdlog::logger> Logger::s_client;

    void Logger::Init()
    {
        std::stringstream ss;
        ss << FileSystem::GetWorkingDir() << "logs/memory_leaks.txt";

        s_memory = spdlog::rotating_logger_mt("Memory Leak", ss.str(), 104857600, 1); //100mb, 1 file.
        s_engine = spdlog::stdout_color_mt("VampEngine");
        s_client = spdlog::stdout_color_mt("Client");
        
        s_memory->set_pattern("%^[%n] [%D %T] (%l) : %v%$");
        s_engine->set_pattern("%^[%n] [%D %T] (%l) {%@}: %v%$");
        s_client->set_pattern("%^[%n] [%D %T] (%l) {%@}: %v%$");
        
        s_memory->set_level(spdlog::level::trace);
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