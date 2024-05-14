#define VAMP_ENTRY_POINT
#include <VampEngine/VampEngine.h>

class Sandbox : public VampEngine::Application
{
    public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }

    private:
};


VampEngine::Application *VampEngine::CreateApplication()
{
    return new Sandbox();
}