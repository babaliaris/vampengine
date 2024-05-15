#include <pch.h>
#include <VampEngine/core/memory/memory_manager.h>

namespace VampEngine
{
    MemoryManager *MemoryManager::s_manager = nullptr;

    MemoryManager::MemoryManager()
    {
    }

    MemoryManager::~MemoryManager()
    {
        VAMP_ASSERT(s_manager->m_blocks.size() == 0, VAMP_WARN("There are memory leaks! Check the log files."));

        //TODO if there are memory leaks, write them to a log file. Implemente a FileSystem FIRST!!!

        //Delete the remaing blocks.
        for (MemoryBlock *block : s_manager->m_blocks)
        {
            VAMP_ASSERT(false, VAMP_WARN("This line should not be reached!"));
            delete block;
        }
    }

    void MemoryManager::Init()
    {
        if (s_manager != nullptr)
        {
            VAMP_WARN("Only one MemoryManager instance is allowed.");
            return;
        }

        s_manager = new MemoryManager();
    }


    void MemoryManager::RemoveBlock(void *pointer)
    {
        //TODO Fix this by impleneting a sorted map for faster deletions!!!
        for (unsigned int i = 0; i < s_manager->m_blocks.size(); i++)
        {
            if (s_manager->m_blocks[i]->pointer == pointer)
            {
                s_manager->m_blocks.erase(s_manager->m_blocks.begin() + i);
            }
        }
    }


    void MemoryManager::Destroy()
    {
        VAMP_ASSERT(s_manager != nullptr);
        delete s_manager;
    }

}
