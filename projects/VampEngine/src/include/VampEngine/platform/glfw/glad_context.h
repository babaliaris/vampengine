#pragma once
#include <VampEngine/core/graphics/graphics.h>

namespace VampEngine
{
    class GladContext : public GraphicsContext
    {
        public:
        GladContext();
        ~GladContext();

        void Init(const GraphicsContext::InitData &data) override;
        void ClearColorBuffer() override;
    };
}