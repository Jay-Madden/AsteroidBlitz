This build uses CMake to generate the makefiles

step 1: run `cmake .`
    - This will generate a platform specific makefile for your system, please do not try to use this makefile on a different machine, regenerate it on a permachine basis
step 4: run make as normal
step 5: run the ./bin/GameStarter exe

sprites: https://opengameart.org/content/complete-spaceship-game-art-pack

inputs: W to go forward 
A and D to rotate left and right (its a bit wonky)

helpers: 
    Engine.cpp and Sprite.cpp
