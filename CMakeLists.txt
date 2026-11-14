cmake_minimum_required(VERSION 3.16)

project(game_project LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 6.2
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(game tetris.cpp)

target_link_libraries(game PRIVATE raylib)
 