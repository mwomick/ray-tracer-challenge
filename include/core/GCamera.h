#ifndef GCamera_DEFINED
#define GCamera_DEFINED

#include "include/core/GMatrix.h"
#include "include/core/GCanvas.h"
#include "include/core/GWorld.h"

class GCamera {
public:
    GCamera(float width, float height, float fov) {
        fWidth = width;
        fHeight = height;
        fFOV = fov;
        fMatrix = GMatrix44();

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
        fPixelSize = (fHalfW * 2.) / this->fWidth;
    }

    void transform(GMatrix44 matrix) {
        fMatrix = matrix * fMatrix;    
    }

    GCanvas render(GWorld& world);

private:
    float fWidth, fHeight, fFOV;
    float fHalfW, fHalfH;
    float fPixelSize;
    GMatrix44 fMatrix;

    GRay ray_for_pixel(float x, float y);
    GTuple sample(GWorld& world, float x, float y);

};

#endif