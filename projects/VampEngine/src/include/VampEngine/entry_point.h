#pragma once

#if defined(VAMP_ENTRY_POINT) && defined(VAMP_AVOID_ERROR_IDE_MARKUP_ANNOYANCE)

    #if defined(VAMP_WINDOWS) || defined(VAMP_LINUX)
        int main(int argc, char **argv)
        {
            VampEngine::Application *app = VampEngine::CreateApplication();

            app->Run();

            delete app;

            return 0;
        }

    #else
        #error Operating System Is Not Supported!
    #endif

#endif
