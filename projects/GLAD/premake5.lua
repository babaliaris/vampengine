project "GLAD"
    targetname "glad"
    kind "StaticLib"
    language "C++"
    cppdialect "c++17"
    targetdir "%{_WORKING_DIR}/builds/%{cfg.shortname}/"
    objdir "%{_WORKING_DIR}/obj/%{prj.name}_%{cfg.shortname}/"

    files {
        "src/**.h",
        "src/**.c"
    }

    includedirs {
        "src/include"
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