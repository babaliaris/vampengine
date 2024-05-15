#pragma once

#include "logger.h"

#ifdef VAMP_DEBUG

    /**
     * DO NOT WRAP FUNCTIONALITY INTO THE <cond> MACRO ARGUMENT,
     * IT IS GOING TO BE STRIPPED AWAY IN DIST AND RELEASE.
    */
    #define VAMP_ASSERT(cond, ...)\
        if ( !(cond) )\
        {\
            VAMP_WARN("[Assertion: {0}]", #cond);\
            __VA_ARGS__;\
        }


    /**
     * Use this to wrap function calls or other type of functionalities, that must
     * be retained in the DIST and RELEASE builds!!!
     * <code> is going to be retained!!!
    */
    #define VAMP_ASSERT_FUNC(code, expected, ...)\
        if ( (code) != (expected) )\
        {\
            VAMP_WARN("[Assertion: {0} != {1}]", #code, #expected);\
            __VA_ARGS__;\
        }

#else
    #define VAMP_ASSERT(cond, ...)
    #define VAMP_ASSERT_FUNC(code, expected, ...) code;

#endif
