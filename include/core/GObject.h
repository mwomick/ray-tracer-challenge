#ifndef GObject_DEFINED
#define GObject_DEFINED

#include "include/core/GRay.h"
#include "include/core/GMaterial.h"
#include "include/core/GIntersections.h"

class GObject {
public:
    virtual int intersect(GRay&, GIntersections&) { return 0; }

    GMaterial& material() { return fMaterial; }
    void setMaterial(GMaterial material) { fMaterial = material; }

    virtual GTuple normal_at(GTuple& point) { return GTuple(0, 0, 0); }

    void transform(GMatrix44 matrix) {
        this->fMatrix = matrix * this->fMatrix;
    }

protected:
    GMatrix44 fMatrix;
    GMaterial fMaterial;
};

#endif