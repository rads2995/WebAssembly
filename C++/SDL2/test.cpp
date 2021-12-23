// SDL2 example and test source code
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    
    SDL_Window* window;
    
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

    SDL_Delay(3000);

    SDL_Quit();

    return (0);
}
