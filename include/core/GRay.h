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
        GMatrix44 dir_matrix = GMatrix44(fMatrix[kSX], fMatrix[kKXY], fMatrix[kKXZ], 0,
                                        fMatrix[kKYX], fMatrix[kSY], fMatrix[kKYZ], 0,
                                        fMatrix[kKZX], fMatrix[kKZY], fMatrix[kSZ], 0,
                                        0, 0, 0, 1);
        
        return dir_matrix * this->fDirection;
    }

    GTuple position(float t) {
        return this->fMatrix * this->fOrigin + this->direction() * t;
    }

    void setMatrix(GMatrix44 matrix) { fMatrix = matrix; }

    GRay transform(GMatrix44 matrix) {
        GRay ray = GRay(fOrigin, fDirection); 
        ray.setMatrix(matrix * fMatrix);
        return ray;
    }

private:
    GTuple fOrigin, fDirection;
    GMatrix44 fMatrix = GMatrix44();
};

#endif