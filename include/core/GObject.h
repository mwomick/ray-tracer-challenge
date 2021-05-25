#ifndef GObject_DEFINED
#define GObject_DEFINED

#include "include/core/GRay.h"
#include "include/core/GMaterial.h"
#include "include/core/GIntersections.h"

class GObject {
public:
    GMaterial& material() { return fMaterial; }
    void setMaterial(GMaterial material) { fMaterial = material; }

    GTuple normal_at(GTuple& point) {
        GTuple obj_normal = fMatrix.inverse() * point;
        GTuple world_normal = fMatrix.inverse().transpose() * obj_normal;
        world_normal.setW(0);
        return local_normal_at(world_normal);
    }

    int intersect(GRay& ray, GIntersections& intersections) {
        GRay r_n = ray.transform(this->fMatrix.inverse());
        return local_intersect(r_n, intersections);
    }

    void transform(GMatrix44 matrix) {
        this->fMatrix = matrix * this->fMatrix;
    }

    GMatrix44 matrix() { return fMatrix; }

protected:
    GMatrix44 fMatrix;
    GMaterial fMaterial;
    virtual GTuple local_normal_at(GTuple& point) { return GTuple(0, 0, 0); }
    virtual int local_intersect(GRay&, GIntersections&) { return 0; }
};

#endif