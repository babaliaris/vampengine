#pragma once
#include <memory>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>


namespace VampEngine
{
    class Logger
    {
        friend class MemoryManager;

        public:
        static void Init();

        static void SetEngineLevel(spdlog::level::level_enum level);
        static void SetClientLevel(spdlog::level::level_enum level);

        inline static std::shared_ptr<spdlog::logger> GetEngineLogger() {return s_engine;}
        inline static std::shared_ptr<spdlog::logger> GetClientLogger() {return s_client;}

        private:
        static std::shared_ptr<spdlog::logger> s_memory;
        static std::shared_ptr<spdlog::logger> s_engine;
        static std::shared_ptr<spdlog::logger> s_client;

        inline static std::shared_ptr<spdlog::logger> GetMemoryLogger() { return s_memory; }
    };
}


#ifdef VAMP_DEBUG
    #define VAMP_TRACE(...) SPDLOG_LOGGER_TRACE(Logger::GetEngineLogger(), __VA_ARGS__)
    #define VAMP_INFO(...) SPDLOG_LOGGER_INFO(Logger::GetEngineLogger(), __VA_ARGS__)
    #define VAMP_WARN(...) SPDLOG_LOGGER_WARN(Logger::GetEngineLogger(), __VA_ARGS__)
    #define VAMP_ERROR(...) SPDLOG_LOGGER_ERROR(Logger::GetEngineLogger(), __VA_ARGS__)
    #define VAMP_FATAL(...) SPDLOG_LOGGER_CRITICAL(Logger::GetEngineLogger(), __VA_ARGS__)


    #define VAMP_CLIENT_TRACE(...) SPDLOG_LOGGER_TRACE(Logger::GetClientLogger(), __VA_ARGS__)
    #define VAMP_CLIENT_INFO(...) SPDLOG_LOGGER_INFO(Logger::GetClientLogger(), __VA_ARGS__)
    #define VAMP_CLIENT_WARN(...) SPDLOG_LOGGER_WARN(Logger::GetClientLogger(), __VA_ARGS__)
    #define VAMP_CLIENT_ERROR(...) SPDLOG_LOGGER_ERROR(Logger::GetClientLogger(), __VA_ARGS__)
    #define VAMP_CLIENT_FATAL(...) SPDLOG_LOGGER_CRITICAL(Logger::GetClientLogger(), __VA_ARGS__)

#else
    #define VAMP_TRACE(...)
    #define VAMP_INFO(...)
    #define VAMP_WARN(...)
    #define VAMP_ERROR(...)
    #define VAMP_FATAL(...)


    #define VAMP_CLIENT_TRACE(...)
    #define VAMP_CLIENT_INFO(...)
    #define VAMP_CLIENT_WARN(...)
    #define VAMP_CLIENT_ERROR(...)
    #define VAMP_CLIENT_FATAL(...)

#endif
