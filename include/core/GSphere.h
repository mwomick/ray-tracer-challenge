#ifndef GSphere_DEFINED
#define GSphere_DEFINED

#include "include/core/GObject.h"
#include "include/core/GRay.h"
#include "include/core/GTuple.h"
#include "include/core/GMaterial.h"
#include "include/core/GIntersection.h"
#include "include/core/GIntersections.h"

class GSphere : public GObject {
public:
    GSphere() { fMaterial = GMaterial(); fMatrix = GMatrix44(); }
    int local_intersect(GRay& ray, GIntersections& dst) override;
    GTuple local_normal_at(GTuple&) override;
};

#endif