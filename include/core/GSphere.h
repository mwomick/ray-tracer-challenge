#ifndef GSphere_DEFINED
#define GSphere_DEFINED

#include "include/core/GRay.h"
#include "include/core/GTuple.h"

class GSphere {
public:
    GSphere() { fOrigin = GTuple(0, 0, 0); fRadius = 1; }
    bool intersect(GRay&, float&, float&);
    void transform(GMatrix44 matrix);
private:
    GTuple fOrigin;
    float fRadius;
    GMatrix44 fMatrix;
};

#endif