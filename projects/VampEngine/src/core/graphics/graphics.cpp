#include <pch.h>
#include <VampEngine/core/graphics/graphics.h>
#include <VampEngine/core/memory/memory_manager.h>
#include <VampEngine/debug/assert.h>

#if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
    #include <VampEngine/platform/glfw/glad_context.h>
#endif


namespace VampEngine
{
    GraphicsContext::GraphicsContext()
    {
    }


    GraphicsContext::~GraphicsContext()
    {
    }


    GraphicsContext *GraphicsContext::CreateContext(const GraphicsTypeE type)
    {
        switch (type)
        {
            case GraphicsTypeE::OPENGL:
            {
                #if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
                return VAMP_NEW(GladContext);
                #endif
            }
            
            default:
            {
                VAMP_ASSERT(false, VAMP_WARN("This line should have not been reached."));
                return nullptr;
            }
        }
    }
}