This build uses CMake to generate the makefiles

**Step 1:** run `cmake .`
    - This will generate a platform specific makefile for your system, please do not try to use this makefile on a different machine, regenerate it on a permachine basis
    
**Step 2:** run make as normal

**Step 3:** cd in bin/

**Step 4:** run ./GameStarter

sprites: https://opengameart.org/content/complete-spaceship-game-art-pack

inputs: W to go forward 
A and D to rotate left and right (its a bit wonky)

helpers: 
    Engine.cpp and Sprite.cpp
