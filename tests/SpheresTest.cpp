/*
#include <iostream>

#include "include/core/GSphere.h"
#include "include/core/GRay.h"
#include "include/core/GTuple.h"
#include "include/core/GIntersection.h"
#include "include/core/GIntersections.h"
#include "include/core/GCanvas.h"

using namespace std;

int main() {
    int WIDTH = 256;
    int HEIGHT = WIDTH;

    GTuple RED = GTuple(1.0, 0.0, 0.0);

    GCanvas canvas = GCanvas(WIDTH, HEIGHT);
    GMatrix44 scale = GMatrix44::Scale(85, 85, 85);
    GTuple ro = GTuple(0, 0, -120);
    GSphere sp = GSphere();
    sp.transform(scale);
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            GTuple rd = GTuple(j-WIDTH/2, HEIGHT/2-i, -115);
            GRay r = GRay(ro, rd);
            float t0, t1;
           if(sp.intersect(r, t0, t1))
                canvas.blit(j, i, RED);
        }
    }

    canvas.writeToFile("spheres.ppm");
}
*/