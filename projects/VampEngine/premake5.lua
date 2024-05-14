project "VampEngine"
    targetname "vampengine"
    kind "StaticLib"
    language "C++"
    cppdialect "c++17"
    targetdir "%{_WORKING_DIR}/builds/%{cfg.shortname}/"
    objdir "%{_WORKING_DIR}/obj/%{prj.name}_%{cfg.shortname}/"

    pchheader "pch.h"
    pchsource "src/pch.cpp"

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp",
        "src/**.c",
    }

    includedirs {
        "src/include",
        "src/include/VampEngine",
        "%{_WORKING_DIR}/external/glfw",
        "%{_WORKING_DIR}/external/spdlog/include"

    }

    defines {
        "SPDLOG_COMPILED_LIB"
    }

    -- -------------------------------|All Platforms|------------------------------- --
    filter{}
    filter "configurations:debug"
        runtime "Debug"
        symbols "on"

    filter{}
    filter "configurations:dist"
        runtime "Release"
        optimize "on"

    filter{}
    filter "configurations:release"
        runtime "Release"
        optimize "on"
    -- -------------------------------|All Platforms|------------------------------- --