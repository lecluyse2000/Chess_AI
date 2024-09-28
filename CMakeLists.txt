cmake_minimum_required(VERSION 3.21)
project(chess_ai)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(chess_ai)

target_sources(chess_ai PRIVATE
)

#Includes the header files from src
target_include_directories(chess_ai PRIVATE
)

target_compile_options(chess_ai PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-g -Wall -Wextra>
)
#Use this command to build: cmake -B build && make -C build
