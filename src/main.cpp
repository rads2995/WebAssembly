// Include SDL and emscripten libraries
#include <SDL2/SDL.h>
#include <emscripten.h>

// Include standard libraries
#include <iostream>

// Global constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

// Create global objects
SDL_Window *window = nullptr;           // Window to be rendering to
SDL_Surface *screenSurface = nullptr;   // Surface contained by the window
SDL_Surface *helloWorld = nullptr;      // Image to load and show on screen

// Function declarations
bool init();
bool loadMedia();
void close();
void render_func();

// Main function
int main() {
    
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        return -1;
    }

    if (!loadMedia()) {
        std::cout << "Failed to load media!" << std::endl;
        return -1;
    }

    // Call Emscripten main loop
    emscripten_set_main_loop(render_func, 60, 1);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void render_func(void) {
    // Fill the surface
    // SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    SDL_BlitSurface(helloWorld, nullptr, screenSurface, nullptr);

    // Update the surface
    SDL_UpdateWindowSurface(window);
}

bool init() {
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL could not initialize! " << SDL_GetError() << std::endl;
        return -1;
    }

    // Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    return success;
}

bool loadMedia() {
    // Loading success flag
    bool success = true;

    // Load splash image
    helloWorld = SDL_LoadBMP("image.bmp");

    if (helloWorld == nullptr) {
        std::cout << "Unable to load image!" << std::endl;
        success = false;
    }

    return success;
}

void close() {
    
    // Deallocate surface
    SDL_FreeSurface(helloWorld);
    helloWorld = nullptr;

    // Destroy window
    SDL_DestroyWindow(window);
    window = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}
