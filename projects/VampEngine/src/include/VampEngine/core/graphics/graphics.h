#pragma once

namespace VampEngine
{
    enum class GraphicsTypeE
    {
        NONE, OPENGL, DIRECTX12, VULKAN
    };

    class GraphicsAPI
    {
        friend class Window;

        public:
        union InitData
        {
            void *data;
        };

        public:
        virtual void Init(const InitData &data) = 0;
        virtual ~GraphicsAPI();

        virtual void ClearColorBuffer() = 0;

        protected:
        GraphicsAPI();

        private:
        static GraphicsAPI *CreateAPI(const GraphicsTypeE type);
    };
}