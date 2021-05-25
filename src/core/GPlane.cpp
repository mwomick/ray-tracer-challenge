#include "include/core/GPlane.h"

#include <cmath>

#include "include/core/GMath.h"

int GPlane::local_intersect(GRay& ray, GIntersections& dst) {
    if(abs(ray.direction().y()) < G_FL_EPSILON) {
        return 0;
    }
    float t = -ray.origin().y() / ray.direction().y();
    GIntersection i = GIntersection(t, this);
    dst.insert(i);
    return 1;
}

GTuple GPlane::local_normal_at(GTuple&) {
    return GTuple(0, 1, 0);
}