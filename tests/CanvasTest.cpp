#include "include/core/GCanvas.h"

int main() {
    const int WIDTH = 256;
    const int HEIGHT = 256;

    GCanvas canvas = GCanvas(WIDTH, HEIGHT);

    GTuple WHITE = GTuple(1.0, 1.0, 1.0);
    GTuple RED = GTuple(1.0, 0.0, 0.0);
    GTuple GREEN = GTuple(0.0, 1.0, 0.0);
    GTuple BLUE = GTuple(0.0, 0.0, 1.0);
    
    for(int i = 0; i < HEIGHT; i++) {
        canvas.blitRow(0, i, WIDTH, WHITE);
    }

    for(int i = 0; i < HEIGHT/3; i++) {
        for(int j = 0; j < WIDTH/3; j++) {
            canvas.blit(j, i, RED);
        }
    }

    for(int i = HEIGHT/3; i < 2*HEIGHT/3; i++) {
        for(int j = WIDTH/3; j < 2*WIDTH/3; j++) {
            canvas.blit(j, i, BLUE);
        }
    }

    for(int i =2*HEIGHT/3; i < HEIGHT; i++) {
        for(int j = 2*WIDTH/3; j < WIDTH; j++) {
            canvas.blit(j, i, GREEN);
        }
    }

    canvas.writeToFile("canvas.ppm");
}