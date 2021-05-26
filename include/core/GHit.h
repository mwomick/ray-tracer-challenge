#ifndef GHit_DEFINED
#define GHit_DEFINED

#include "include/core/GMath.h"

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
        fReflect = ray->direction().reflect(fNormal);
        fOver = fPoint + fNormal * G_FL_EPSILON;
    }

    bool isInside() { return fInside; }
    GTuple point() { return fPoint; }
    GTuple eye() { return fEye; }
    GTuple normal() { return fNormal; }
    GObject* object() { return fIntersection->object(); }
    GTuple over() { return fOver; }
    GRay reflect() { return GRay(fOver, fReflect); }
    
    float t() { return fIntersection->t(); }

private:
    GIntersection* fIntersection;
    GTuple fPoint, fEye, fNormal, fOver, fReflect;
    bool fInside;
};

#endif