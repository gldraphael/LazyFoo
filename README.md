This repository should help me track my progress of following the SDL2 tutorials at <http://lazyfoo.net>

### Development Environment
**Operating System:** OSX 10.11.6   
**Compiler:** Clang   
**Text Editor:** Visual Studio Code

#### Setting up your development environment on your mac

1. Run `xcode-select --install` on the terminal. (I had to run this again after upgrading OSX to El Capitan)
1. Install [homebrew](http://brew.sh)
1. Install SDL2 by typing `brew install sdl2`
1. Install Visual Studio Code (or any other text editor of your choice)
1. Done! You should be able to compile a file using the command: `clang++ filename.cpp -lSDL2 -g`