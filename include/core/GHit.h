#ifndef GHit_DEFINED
#define GHit_DEFINED

#include <iostream>

class GHit {
public:
    GHit(GIntersection* intersection, GRay* ray) {
        fIntersection = intersection;
        fPoint = ray->position(intersection->t());
        fEye = -ray->direction();
        fNormal = intersection->object()->normal_at(fPoint);
        fInside = false;
        if (this->fNormal.dot(fEye) < 0) {
            fNormal = -fNormal;
            fInside = true;
        }
    }

    bool isInside() { return fInside; }
    GTuple point() { return fPoint; }
    GTuple eye() { return fEye; }
    GTuple normal() { return fNormal; }
    GObject* object() { return fIntersection->object(); }

private:
    GIntersection* fIntersection;
    GTuple fPoint, fEye, fNormal;
    bool fInside;
};

#endif