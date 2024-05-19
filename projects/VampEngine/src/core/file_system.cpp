#include <pch.h>
#include <VampEngine/core/file_system.h>
#include <VampEngine/debug/assert.h>

/**
 * THIS FILE CAN NOT USE THE MEMORY MANAGER BECAUSE OF CIRCULAR DEPEDENCY.
 * USE NEW AND DELETE VERY CAREFULLY!!!
*/

#if defined(VAMP_LINUX) || defined(VAMP_WINDOWS)
    #include <platform/cpp_standard/cpp_filesystem.h>
#endif

namespace VampEngine
{
    FileSystem *FileSystem::s_ref = nullptr;

    FileSystem::FileSystem()
    : m_workingDirectory(VAMP_WORKING_DIR)
    {
    }

    FileSystem::~FileSystem()
    {
    }

    void FileSystem::Init()
    {
        //Singleton Pattern.
        if (s_ref)
        {
            VAMP_WARN("FileSystem::s_ref should be initialized only once!");
            return;
        }

        //Anyting that supports cpp standard filesystem.
        #if defined(VAMP_LINUX) || defined(VAMP_WINDOWS)
            s_ref = new CppFileSystem();
        #endif
    }

    void FileSystem::Destroy()
    {
        delete s_ref;
    }
}