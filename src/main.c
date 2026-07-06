#include <SDL3/SDL.h>
#include <inttypes.h>

#include "grid.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Could not initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Conway's Wallpaper",
        640,
        480,
        0
    );

    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    uint8_t grid[COLS][ROWS] = {}; // initialize grid
                                   // 0 = dead
                                   // 1 = alive

    initialize(grid);

    SDL_Renderer* renderer = SDL_GetRenderer(window);

    while (true) {

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
