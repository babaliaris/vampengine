#include <pch.h>
#include "cpp_filesystem.h"
#include <fstream>
#include <sstream>
#include <string>
#include <VampEngine/debug/assert.h>

namespace VampEngine
{
    CppFileSystem::CppFileSystem()
    : FileSystem()
    {
    }

    CppFileSystem::~CppFileSystem()
    {
    }

    std::string CppFileSystem::ReadFileImpl(const std::string &filename)
    {
        //Create the full path of the file.
        std::stringstream filepath, data;
        filepath << this->GetWorkingDir() << filename;

        //Try to open the file.
        std::ifstream file(filepath.str());

        //Check if the file was opened successfully.
        if (!file.is_open())
        {
            VAMP_ERROR("The following file could not be opened: {0}", filepath.str());
            return "";
        }

        //Read the entire file at once.
        data << file.rdbuf();

        return data.str();
    }
}