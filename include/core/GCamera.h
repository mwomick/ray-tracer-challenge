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
    }

    void transform(GMatrix44 matrix) {
        fMatrix = matrix * fMatrix;    
    }

    GCanvas render(GWorld& world);

    float pixel_size();
private:
    float fWidth, fHeight, fFOV;
    float fHalfW, fHalfH;
    GMatrix44 fMatrix;

    GRay ray_for_pixel(float x, float y);
};

#endif