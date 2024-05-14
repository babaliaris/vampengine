project "Sandbox"
    targetname "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "c++17"
    targetdir "%{_WORKING_DIR}/builds/%{cfg.shortname}/"
    objdir "%{_WORKING_DIR}/obj/%{prj.name}_%{cfg.shortname}/"

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp",
        "src/**.c",
    }

    includedirs {
        "src/",
        "%{_WORKING_DIR}/projects/VampEngine/src/include"

    }

    links {
        "VampEngine", "spdlog",
        "GLFW", "GLAD"
    }

    defines {
        "VAMP_AVOID_ERROR_IDE_MARKUP_ANNOYANCE",
        "SPDLOG_COMPILED_LIB"
    }

    -- Debug All Operate Systems & Configurations
    filter{}
    filter "configurations:debug"
        runtime "Debug"
        symbols "on"

    -- Dist All Operate Systems & Configurations
    filter{}
    filter "configurations:dist"
        runtime "Release"
        optimize "on"

    -- Release All Operate Systems & Configurations
    filter{}
    filter "configurations:release"
        runtime "Release"
        optimize "on"

    -- Linux All Configurations
    filter{}
    filter "system:Linux"

        defines {
            "VAMP_LINUX"
        }

        links {
            "GL", "X11", "pthread",
            "Xrandr", "Xi", "ldl"
        }


    -- Windows All Configurations
    filter{}
    filter "system:Windows"

        defines {
            "VAMP_WINDOWS"
        }

        links {
            "opengl32"
        }