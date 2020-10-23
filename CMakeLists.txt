cmake_minimum_required(VERSION 3.5)

# set the project name
project(GameStarter)

# specify the C++ standard
add_compile_options(-std=c++17)

include_directories(/usr/local/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

include_directories(SYSTEM ${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(GameStarter 
    game/src/Engine.cpp 
    game/src/main.cpp 
    game/src/Ship.cpp 
    game/src/Sprite.cpp 
    game/src/GameObject.cpp
)
target_link_libraries(GameStarter PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

