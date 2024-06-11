#pragma once
#include <string>
#include <vector>

namespace VampEngine
{
    struct MemoryBlock
    {
        void *pointer;
        std::string file;
        long long line;

        MemoryBlock(void *ptr, const std::string &file, long long line)
        : pointer(ptr), file(file), line(line)
        {
        }
    };


    class MemoryManager
    {
        friend class Application;

        public:
        template <typename T, typename... Args> static T *PushBlock(const char *file, long long line, const Args... tail)
        {
            T *new_object = new T(tail...);

            s_manager->m_blocks.push_back(new MemoryBlock(new_object, file, line));

            return new_object;
        }

        static void RemoveBlock(void *pointer);

        protected:
        MemoryManager();
        ~MemoryManager();

        private:
        std::vector<MemoryBlock *> m_blocks;
        static MemoryManager *s_manager;

        static void Init();
        static void Destroy();
    };
}


#ifdef VAMP_DEBUG

    //TODO Maybe overload delete for cleaner code?
    #define VAMP_NEW(object_type, ...)\
        VampEngine::MemoryManager::PushBlock<object_type>(__FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__)


    #define VAMP_DELETE(object)\
        VampEngine::MemoryManager::RemoveBlock(object);\
        delete object

#else
    #define VAMP_NEW(object_type, ...) new object_type(__VA_ARGS__)
    #define VAMP_DELETE(object) delete object

#endif