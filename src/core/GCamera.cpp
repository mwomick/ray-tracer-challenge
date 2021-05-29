#include "include/core/GCamera.h"

#include <cmath>
#include <stdlib.h>

GCanvas GCamera::render(GWorld& world) {
    GCanvas canvas = GCanvas(this->fWidth, this->fHeight);
    for(int y = 0; y < this->fHeight; y++) {
        for(int x = 0; x < this->fWidth; x++) {
            // GRay r = ray_for_pixel(x+.5, y+.5);
            // GTuple c = world.color_at(r, 4);
            GTuple c = sample(world, x, y);
            canvas.blit(x, y, c);
        }
    }
    return canvas;
}

GRay GCamera::ray_for_pixel(float x, float y) {
    float x_offset = x * this->fPixelSize;
    float y_offset = y * this->fPixelSize;

    float world_x = this->fHalfW - x_offset;
    float world_y = this->fHalfH - y_offset; 

    GTuple pixel = this->fMatrix.inverse() * GTuple(world_x, world_y, -1);
    GTuple origin = this->fMatrix.inverse() * GTuple(0, 0, 0);
    GTuple dir = (pixel - origin).normalize();
    
    return GRay(origin, dir);
}

GTuple GCamera::sample(GWorld& world, float x, float y) {
    GTuple average = GTuple(0, 0, 0);

    float block_size = .2;
    int jitter = 9.;
    float left = 0.;
    float top = 0.;

    float i = 0;

    while(top < 1.) {
        left = 0.;
        while(left < 1.) {
            float rand_x = block_size * ((float)(rand() % jitter) / (float)jitter);
            float rand_y = block_size * ((float)(rand() % jitter) / (float)jitter);
            GRay ray = ray_for_pixel(x+left+rand_x, y+top+rand_y);
            GTuple c = world.color_at(ray, 5);
            i = i + 1.;
            average = average + c;
            left += block_size;
        }
        top += block_size;
    }

    average = average / i;
    return average;
}