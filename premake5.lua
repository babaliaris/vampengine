workspace "VampEngine"
    configurations { "debug", "dist", "release"}
    platforms "x64"
    startproject "Sandbox"


-- ||||||||||||||||||||Include Projects|||||||||||||||||||| --

-- include "projects/VampEngine"
include "projects/VampEngine"
include "projects/Sandbox"
include "projects/Tests"

group "external"
    include "external/glfw"
    include "external/googletest/googletest"
group ""

-- ||||||||||||||||||||Include Projects|||||||||||||||||||| --