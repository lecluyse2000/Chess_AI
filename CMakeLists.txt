cmake_minimum_required(VERSION 3.21)
project(
    chess_ai 
    VERSION 0.0.1
    DESCRIPTION "A chess engine built from the ground up using c++20"
    LANGUAGES CXX C)

if (CMAKE_GENERATOR MATCHES ".*Visual Studio.*|.*Xcode.*|Multi-Config")
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Available build configurations" FORCE)
else()
    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
    endif()
endif()

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS $<$<CONFIG:Debug>:ON>)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(chess_ai)

target_sources(chess_ai PRIVATE
    "src/main.cpp"
    "src/game.cpp"
    "src/engine.cpp"
    "src/ui.cpp"
)

target_include_directories(chess_ai PRIVATE
    "src"
    "src/util"
)

target_compile_definitions(chess_ai PRIVATE CURRENT_VERSION="${CMAKE_PROJECT_VERSION}"
                                            $<$<CONFIG:Release>:NDEBUG>)

if (MSVC)
    target_compile_options(chess_ai PRIVATE 
        $<$<CONFIG:Debug>:/W4>
        $<$<CONFIG:Release>:/O2>
    )
else()
    target_compile_options(chess_ai PRIVATE 
        $<$<CONFIG:Debug>:-g -Wall -Wextra -Wshadow -Wconversion -Wpedantic>
        $<$<CONFIG:Release>:-O2>
    )
endif()

target_compile_definitions(chess_ai PRIVATE 
)

#Use this command to build on Linux: cmake -B build && make -C build
