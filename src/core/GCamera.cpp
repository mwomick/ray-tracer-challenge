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
    GTuple sum = GTuple(0, 0, 0);
    GTuple storage[26];

    int max = 26;
    int min = 9;
    int i = 0;

    GTuple average = GTuple(0, 0, 0);
    GTuple mse = GTuple(0, 0, 0);

    for(; (i < min || (mse.x() + mse.y() + mse.z()) > 0.0006) && i < max; i++) {
        int rand_x = rand() % 26;
        float scaled_x = rand_x / 26.;
        int rand_y = rand() % 26;
        float scaled_y = rand_y / 26.;
        GRay ray = ray_for_pixel(x+scaled_x, y+scaled_y);
        GTuple c = world.color_at(ray, 5);

        sum = sum + c;
        storage[i] = c;

        average = GTuple(0, 0, 0);
        for(int j = 0; j <= i; j++) {
            average = average + storage[j];
        }
        average = average / (i+1);

        mse = GTuple(0, 0, 0);
        for(int j = 0; j <= i; j++) {
            mse = mse + (storage[j] - average) * (storage[j] - average);            
        }
        mse = mse / (i+1);
        
        // std::cout <<(mse.x() + mse.y() + mse.z())/(3); 
    }
    if(i!=9 && i!=26) {
        std::cout << i << "\n";
    }
    return average;
}