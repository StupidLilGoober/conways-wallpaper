cmake_minimum_required(VERSION 3.20)

project(conways_wallpaper C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-3.2.0
)

FetchContent_MakeAvailable(SDL3)

add_executable(conways_wallpaper
    src/main.c
)

target_link_libraries(conways_wallpaper PRIVATE SDL3::SDL3)

target_include_directories(conways_wallpaper PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if (MSVC)
    target_compile_options(conways_wallpaper PRIVATE /W4)
else()
    target_compile_options(conways_wallpaper PRIVATE -Wall -Wextra -Wpedantic)
endif()
