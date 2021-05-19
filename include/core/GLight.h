#ifndef GLight_DEFINED
#define GLight_DEFINED

#include "include/core/GTuple.h"

class GLight {
public:
    GLight() {
        fIntensity = GTuple(1., 1., 1.);
        fPosition = GTuple(0., 0., 0.);
    }

    GLight(GTuple intensity, GTuple position) {
        fIntensity = intensity;
        fPosition = position;
    }

    GTuple intensity() { return fIntensity; }
    GTuple position() { return fPosition; }

private:
    GTuple fIntensity, fPosition;
};

#endif