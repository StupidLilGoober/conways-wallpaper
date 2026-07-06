#pragma once

#include <SDL3/SDL.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

#include "graphics.h"

#define CELL_ALIVE 1
#define CELL_DEAD 0

#define ROWS 120
#define COLS 160

#define DENSITY 30

void initialize(uint8_t grid[COLS][ROWS]) {
    srand(time(NULL));

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            grid[i][j] = (rand() % 100) < DENSITY;
        }
    }
}

int check_neighbors(uint8_t grid[COLS][ROWS], int x, int y) {
    int neighbors = 0;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0)
                continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < COLS &&
                ny >= 0 && ny < ROWS &&
                grid[nx][ny] == CELL_ALIVE) {
                neighbors++;
            }
        }
    }

    return neighbors;
}

void simulation(uint8_t grid[COLS][ROWS], uint8_t* buffer) {
    uint8_t next[COLS][ROWS];

    memset(buffer, 0, WIDTH * HEIGHT * 3);

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            int neighbors = check_neighbors(grid, i, j);

            if (grid[i][j] == CELL_ALIVE) {
                if (neighbors < 2 || neighbors > 3) {
                    next[i][j] = CELL_DEAD;
                } else {
                    next[i][j] = CELL_ALIVE;
                }
            } else {
                if (neighbors == 3) {
                    next[i][j] = CELL_ALIVE;
                } else {
                    next[i][j] = CELL_DEAD;
                }
            }

            draw_cell(next, buffer, i, j);
        }
    }

    memcpy(grid, next, sizeof(next));
}
