#ifndef GSphere_DEFINED
#define GSphere_DEFINED

#include "include/core/GRay.h"
#include "include/core/GTuple.h"

class GSphere {
public:
    GSphere() {}
    bool intersect(GRay&, float&, float&);
    void transform(GMatrix44 matrix);
    GTuple normal_at(GTuple& point);
private:
    GMatrix44 fMatrix;
};

#endif