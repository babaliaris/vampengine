#include <pch.h>
#include <VampEngine/platform/glfw/glad_context.h>
#include <glad/glad.h>
#include <VampEngine/debug/logger.h>

namespace VampEngine
{
    GladContext::GladContext()
    : GraphicsAPI()
    {
    }


    GladContext::~GladContext()
    {
    }


    void GladContext::Init(const GraphicsAPI::InitData &data)
    {
        if (!gladLoadGLLoader((GLADloadproc)data.data))
        {
            VAMP_ERROR("[GLAD] Failed to initialize GLAD.");
        }
    }


    void GladContext::ClearColorBuffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }


    void GladContext::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g,b, a);
    }
}