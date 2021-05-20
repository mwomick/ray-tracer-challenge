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


    GSphere sp = GSphere();
    sp.material().setColor(GTuple(1, 0.2, 1));
    GMatrix44 transform = GMatrix44::Scale(1., 1., 1.);
    sp.transform(transform);
    GLight light = GLight(GTuple(1, 1, 1), GTuple(-10, 10, -10));
    GTuple ro = GTuple(0, 0, -7);
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            GTuple rd = (GTuple(j-WIDTH/2, HEIGHT/2-i, 800)-ro).normalize();
            GRay r = GRay(ro, rd);
            float t0, t1;
            if(sp.intersect(r, t0, t1)) {
                GTuple point = r.position(t0);
                GTuple normal = sp.normal_at(point);
                GTuple eye = -rd;
                GTuple color = sp.material().lighting(light, point, eye, normal);
                canvas.blit(j, i, color);
            }
        }
    }

    canvas.writeToFile("phong.ppm");
}
*/