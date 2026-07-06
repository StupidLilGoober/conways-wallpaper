#include <SDL3/SDL.h>

#define WIDTH 640
#define HEIGHT 480

#define CELL_ALIVE 1
#define CELL_DEAD 0

#define ROWS 120
#define COLS 160

#define RESET_TIME 15
#define FPS 60
#define RESET_FRAMES (RESET_TIME * FPS)

void draw_cell(uint8_t grid[COLS][ROWS], uint8_t *buffer, int i, int j) {
    if (grid[i][j] == CELL_ALIVE) {
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                int px = i * 4 + x;
                int py = j * 4 + y;

                int index = (py * WIDTH + px) * 3;

                buffer[index + 0] = 0;   // red
                buffer[index + 1] = 255; // green
                buffer[index + 2] = 0;   // blue
            }
        }
    }
}
