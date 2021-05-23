#include "include/core/GCamera.h"
#include <cmath>

GCanvas GCamera::render(GWorld& world) {
    GCanvas canvas = GCanvas(this->fWidth, this->fHeight);
    for(int y = 0; y < this->fHeight; y++) {
        for(int x = 0; x < this->fWidth; x++) {
            GRay r = ray_for_pixel(x, y);
            GTuple c = world.color_at(r);
            canvas.blit(x, y, c);
        }
    }
    return canvas;
}

GRay GCamera::ray_for_pixel(float x, float y) {
    float x_offset = (x + 0.5) * this->pixel_size();
    float y_offset = (y + 0.5) * this->pixel_size();

    float world_x = this->fHalfW - x_offset;
    float world_y = this->fHalfH - y_offset; 

    GTuple pixel = this->fMatrix.inverse() * GTuple(world_x, world_y, -1);
    GTuple origin = this->fMatrix.inverse() * GTuple(0, 0, 0);
    GTuple dir = (pixel - origin).normalize();
    
    return GRay(origin, dir);
}

float GCamera::pixel_size() {
    float half_view = tan(this->fFOV/2.);
    float aspect = this->fWidth / this->fHeight;
    if(aspect >= 1) {
        this->fHalfW = half_view;
        this->fHalfH = half_view / aspect;
    }
    else {
        this->fHalfW = half_view * aspect;
        this->fHalfH = half_view;
    }
    return (fHalfW * 2.) / this->fWidth;
}