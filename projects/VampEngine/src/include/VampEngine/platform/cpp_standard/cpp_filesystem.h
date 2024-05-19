#pragma once
#include <VampEngine/core/file_system.h>

namespace VampEngine
{
    class CppFileSystem : public FileSystem
    {
        public:
        CppFileSystem();
        ~CppFileSystem();

        std::string ReadFileImpl(const std::string &filename) override;
    };
}