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

    GTuple normal_at(GTuple& point) {
        GTuple obj_normal = fMatrix.inverse() * point;
        GTuple world_normal = fMatrix.inverse().transpose() * obj_normal;
        world_normal.setW(0);
        return world_normal.normalize();
    }

    void transform(GMatrix44 matrix) {
        this->fMatrix = matrix * this->fMatrix;
    }

protected:
    GMatrix44 fMatrix;
    GMaterial fMaterial;
};

#endif