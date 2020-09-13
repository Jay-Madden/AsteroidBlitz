cmake_minimum_required(VERSION 3.10)

# set the project name
project(GameStarter)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(GameStarter game/src/Engine.cpp game/src/main.cpp game/src/Ship.cpp game/src/GameObject.cpp)
target_link_libraries(GameStarter ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})