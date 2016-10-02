This repository should help me track my progress of following the SDL2 tutorials at [lazyfoo.net](http://lazyfoo.net). If you're following the tutorials at [lazyfoo.net](http://lazyfoo.net) this should help you too.

### Using this repo

1. Clone the repository (or download a ZIP)
1. The code for the individual tutorials are in separate folders. `cd` to the folder you'd like to build.
1. Use `make` to build the tutorial code
1. Use `./a.out` to run the code

### Development Environment
**Operating System:** OSX 10.11.6   
**Compiler:** Clang   
**Text Editor:** Visual Studio Code

#### Setting up a mac for development

1. Run `xcode-select --install` on the terminal. (I had to run this again after upgrading OSX to El Capitan)
1. Install [homebrew](http://brew.sh)
1. Install SDL2 by typing: `brew install sdl2 --universal`
1. Install Visual Studio Code (or any other text editor of your choice)
1. Done! You should be able to compile SDL2 code with: `clang++ filename.cpp -lSDL2 -g`

### Development Environment
**Operating System:** Ubuntu 16.04 LTS   
**Compiler:** Clang   
**Text Editor:** Visual Studio Code

#### Setting up Ubuntu 16.04 LTS for development

1. Install clang (if you don't already have it) with: `sudo apt-get install clang`
1. Install SDL2 by typing: `sudo apt-get install libsdl2-dev`
1. Install Visual Studio Code (or any other text editor of your choice) from [here](http://code.visualstudio.com/)
1. Done! You should be able to compile SDL2 code with: `clang++ filename.cpp -lSDL2 -g`
