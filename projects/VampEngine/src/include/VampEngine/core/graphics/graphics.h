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

        virtual void SetClearColor(float r, float g, float b, float a);
        virtual void ClearColorBuffer();

        protected:
        GraphicsAPI();

        private:
        static GraphicsAPI *CreateAPI(const GraphicsTypeE type);
    };
}