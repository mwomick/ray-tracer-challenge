#include "include/core/GWorld.h"
#include <iostream>

GIntersections GWorld::intersect_world(GRay& ray) {
    GIntersections res = GIntersections();
    for(GObject* o : this->fObjects) {
        o->intersect(ray, res);
    }
    return res;
};