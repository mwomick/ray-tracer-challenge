#ifndef GPlane_DEFINED
#define GPlane_DEFINED

#include "include/core/GObject.h"

class GPlane : public GObject {
public:
    GPlane() { fMaterial = GMaterial(); fMatrix = GMatrix44(); }
    int local_intersect(GRay& ray, GIntersections& dst) override;
    GTuple local_normal_at(GTuple&) override;
};

#endif