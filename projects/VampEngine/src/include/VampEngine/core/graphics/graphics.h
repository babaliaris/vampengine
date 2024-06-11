#pragma once

namespace VampEngine
{
    enum class GraphicsTypeE
    {
        NONE, OPENGL, DIRECTX12, VULKAN
    };

    class GraphicsContext
    {
        friend class Window;

        public:
        union InitData
        {
            void *data;
        };

        public:
        virtual void Init(const InitData &data) = 0;
        virtual ~GraphicsContext();

        virtual void ClearColorBuffer() = 0;

        protected:
        GraphicsContext();

        private:
        static GraphicsContext *CreateContext(const GraphicsTypeE type);
    };
}