#include <pch.h>
#include <VampEngine/platform/glfw/glad_context.h>
#include <glad/glad.h>
#include <VampEngine/debug/logger.h>

namespace VampEngine
{
    GladContext::GladContext()
    : GraphicsContext()
    {
    }


    GladContext::~GladContext()
    {
    }


    void GladContext::Init(const GraphicsContext::InitData &data)
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
}