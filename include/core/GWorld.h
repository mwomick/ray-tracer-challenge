#ifndef GWorld_DEFINED
#define GWorld_DEFINED

#include <vector>

#include "include/core/GObject.h"
#include "include/core/GIntersections.h"
#include "include/core/GLight.h"
#include "include/core/GRay.h"

class GWorld {
public:
    GIntersections intersect_world(GRay ray);
    void add(GObject* object) { fObjects.push_back(object); }

private:
    GLight fLight;
    std::vector<GObject*> fObjects;
};

#endif