#include <SDL3/SDL.h>
#include <stdio.h>
#include <inttypes.h>

#include "grid.h"

int main() {
    uint8_t grid[COLS][ROWS] = { 0 }; // initialize grid
                                      // 0 = dead
                                      // 1 = alive

    initialize(grid);

    bool running = true;

    uint8_t framebuffer[WIDTH * HEIGHT * 3];

    int frames = 0;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        simulation(grid, framebuffer);

        fwrite(
            framebuffer,
            1,
            sizeof(framebuffer),
            stdout
        );

        fflush(stdout);

        frames++;

        if (frames >= RESET_FRAMES) {
            initialize(grid);
            frames = 0;
        }

        SDL_Delay(1000 / FPS);
    }

    SDL_Quit();
    return 0;
}
