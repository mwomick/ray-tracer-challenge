#ifndef GHit_DEFINED
#define GHit_DEFINED

#include "include/core/GMath.h"

class GHit {
public:
    GHit(GIntersection* intersection, GRay* ray/*, float prev_refractivity*/) {
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
        fUnder = fPoint - fNormal * G_FL_EPSILON;
        fRefractiveIndex1 = 1.;
        fRefractiveIndex2 = intersection->object()->material().refractive_index();
    }

    bool isInside() { return fInside; }
    GTuple point() { return fPoint; }
    GTuple eye() { return fEye; }
    GTuple normal() { return fNormal; }
    GObject* object() { return fIntersection->object(); }
    GTuple over() { return fOver; }
    GTuple under() { return fUnder; }
    GRay reflect() { return GRay(fOver, fReflect); }
    float n1() { return fRefractiveIndex1; }
    float n2() { return fRefractiveIndex2; }

    void setRefraction(float n1, float n2) { fRefractiveIndex1 = n1; fRefractiveIndex2 = n2; }

    float t() { return fIntersection->t(); }

private:
    GIntersection* fIntersection;
    GTuple fPoint, fEye, fNormal, fOver, fReflect, fUnder;
    float fRefractiveIndex1, fRefractiveIndex2;
    bool fInside;
};

#endif