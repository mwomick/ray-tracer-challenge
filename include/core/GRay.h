#ifndef GRay_DEFINED
#define GRay_DEFINED

#include "include/core/GTuple.h"
#include "include/core/GMatrix.h"

class GRay {
public:
    GRay(GTuple origin, GTuple direction) {
        this->fOrigin = origin;
        this->fDirection = direction;
    }

    GTuple origin() {
        return this->fMatrix * this->fOrigin;
    }

    GTuple direction() {
        return this->fMatrix * this->fDirection;
    }

    GTuple position(float t) {
        return this->fMatrix * this->fOrigin + this->fMatrix * this->fDirection * t;
    }

    void transform(GMatrix44 matrix) {
        this->fMatrix = this->fMatrix * matrix;
    }

private:
    GTuple fOrigin, fDirection;
    GMatrix44 fMatrix;
};

#endif