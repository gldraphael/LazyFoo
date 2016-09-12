#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

/*
 * CONSTANTS
 */

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 374;

// Key press surfaces constants
enum KeyPressSurface
{
    DEFAULT,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    TOTAL
};

/*
 * FUNCTION DECLARATIONS
 */

// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Loads individual image
SDL_Surface* loadSurface(std::string path);

/*
 * GLOBAL VARIABLES
 */

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurface[TOTAL];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

/*
 * FUNCTION DEFINITIONS
 */
bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create window
        gWindow = SDL_CreateWindow(
            "SDL Key Presses",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Set window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia()
{
    // Load default surface
    gKeyPressSurface[KeyPressSurface::DEFAULT] = loadSurface("img/prompt.bmp");
    if (gKeyPressSurface[KeyPressSurface::DEFAULT] == NULL)
    {
        return false;
    }

    // Load up surface
    gKeyPressSurface[KeyPressSurface::UP] = loadSurface("img/up.bmp");
    if (gKeyPressSurface[KeyPressSurface::UP] == NULL)
    {
        return false;
    }

    // Load down surface
    gKeyPressSurface[KeyPressSurface::DOWN] = loadSurface("img/down.bmp");
    if (gKeyPressSurface[KeyPressSurface::DOWN] == NULL)
    {
        return false;
    }

    // Load left surface
    gKeyPressSurface[KeyPressSurface::LEFT] = loadSurface("img/left.bmp");
    if (gKeyPressSurface[KeyPressSurface::LEFT] == NULL)
    {
        return false;
    }

    // Load right surface
    gKeyPressSurface[KeyPressSurface::RIGHT] = loadSurface("img/right.bmp");
    if (gKeyPressSurface[KeyPressSurface::RIGHT] == NULL)
    {
        return false;
    }

    return true;
}

SDL_Surface* loadSurface(std::string path)
{
    // Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }

    return loadedSurface;
}

void close()
{
    // Deallocate surfaces
    for(int i = 0; i < KeyPressSurface::TOTAL; i++)
    {
        SDL_FreeSurface(gKeyPressSurface[i]);
        gKeyPressSurface[i] = NULL;
    }

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[])
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Start up SDL and create window
    if(!init())
    {
        printf("Failed to initialize!\n");
        return -1;
    }
    
    //Load media
    if(!loadMedia())
    {
        printf("Failed to load media!\n");
        return -1;
    }

    gCurrentSurface = gKeyPressSurface[KeyPressSurface::DEFAULT];
    
    while(!quit)
    {
        // Handle events on queue
        while(SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if(e.type == SDL_KEYDOWN) //User presses a key
            {
                //Select surfaces based on key press
                switch(e.key.keysym.sym)
                {
                    case SDLK_UP:
                        gCurrentSurface = gKeyPressSurface[KeyPressSurface::UP];
                        break;

                    case SDLK_DOWN:
                        gCurrentSurface = gKeyPressSurface[KeyPressSurface::DOWN];
                        break;

                    case SDLK_LEFT:
                        gCurrentSurface = gKeyPressSurface[KeyPressSurface::LEFT];
                        break;

                    case SDLK_RIGHT:
                        gCurrentSurface = gKeyPressSurface[KeyPressSurface::RIGHT];
                        break;

                    default:
                        gCurrentSurface = gKeyPressSurface[KeyPressSurface::DEFAULT];
                        break;
                }
            }
        }

        // Blit the current surface
        SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
        // Update the surface
        SDL_UpdateWindowSurface(gWindow);
        // Wait 100ms
        SDL_Delay(100);
    }

    //Free resources and close SDL
    close();

    return 0;
}