#pragma once
#include <string>

/*
*   These are some default "assumed" directories. If the user is running the executable from a different directory,
*   they should change the working directory at runtime or move any assets relative to that directory and
*   still adjust the working directory at runtime.
*/
#if defined(VAMP_LINUX)
    //Program is assumed to be run from within this projects root directory.
    #define VAMP_WORKING_DIR "./"

#elif defined(VAMP_WINDOWS) || defined(_MSC_BUILD)
    //Visual studio will run the executable within builds/<config_platform>/
    //so step back two directories.
    #define VAMP_WORKING_DIR "../../"

#else
    #define VAMP_WORKING_DIR "./"

#endif

namespace VampEngine
{
    class FileSystem
    {
        friend class Application;

        public:

        static inline std::string ReadFile(const std::string &filename) { return s_ref->ReadFileImpl(filename); };
        static inline std::string GetWorkingDir() { return s_ref->m_workingDirectory; }
        static inline void SetWorkingDir(const std::string &dir) { s_ref->m_workingDirectory = dir; }

        protected:
        FileSystem();
        virtual ~FileSystem();
        static void Init();
        static void Destroy();

        virtual std::string ReadFileImpl(const std::string &filename) = 0;

        private:
        static FileSystem *s_ref;
        std::string m_workingDirectory;
    };
}