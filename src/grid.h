#pragma once

#include <SDL3/SDL.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

#define CELL_ALIVE 1
#define CELL_DEAD 0

#define ROWS 120
#define COLS 160

#define DENSITY 30

void initialize(uint8_t grid[COLS][ROWS]) {
    srand(NULL);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; i++) {
            grid[i][j] = (rand() % 100) < DENSITY;
        }
    }
}

void simulation(uint8_t grid[160][120], SDL_Renderer* render) {

}
