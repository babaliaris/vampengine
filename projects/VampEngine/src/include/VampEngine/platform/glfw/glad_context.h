#pragma once
#include <VampEngine/core/graphics/graphics.h>

namespace VampEngine
{
    class GladContext : public GraphicsAPI
    {
        public:
        GladContext();
        ~GladContext();

        void Init(const GraphicsAPI::InitData &data) override;
        void ClearColorBuffer() override;
        void SetClearColor(float r, float g, float b, float a) override;
    };
}