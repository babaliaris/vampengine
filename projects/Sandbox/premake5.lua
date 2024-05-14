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
        "VampEngine"
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