#include <iostream>

#include "include/core/GCanvas.h"
#include "include/core/GMatrix.h"

using namespace std;

int main() {

    int WIDTH = 256;
    int HEIGHT = WIDTH;
    int RADIUS = WIDTH/4;

    GTuple RED = GTuple(1.0, 0.0, 0.0);

    GCanvas canvas = GCanvas(WIDTH, HEIGHT);

    GMatrix44 radius = GMatrix44::Translate(RADIUS, RADIUS, 0);
    GMatrix44 center = GMatrix44::Translate(WIDTH/2, HEIGHT/2, 0);


    for(int i = 0; i < 12; i++) {
        GMatrix44 rotate = GMatrix44::RotateZ(i*0.52359);
        GTuple point = GTuple(0, 0, 0);
        point = radius*point;
        point = rotate*point;
        point = center*point;
        canvas.blit(point.x(), point.y(), RED);
    }

    canvas.writeToFile("transformations.ppm");
}