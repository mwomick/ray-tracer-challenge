#ifndef GWorld_DEFINED
#define GWorld_DEFINED

#include <vector>

#include "include/core/GObject.h"
#include "include/core/GIntersections.h"
#include "include/core/GLight.h"
#include "include/core/GRay.h"
#include "include/core/GHit.h"

class GWorld {
public:
    GIntersections intersect_world(GRay& ray);
    void add(GObject* object) { fObjects.push_back(object); }
    void add(GLight* light) { fLight = light; }

    GTuple shade_hit(GHit* hit) {
        return hit->object()->material().lighting(this->fLight, 
                                                    hit->point(), 
                                                    hit->eye(), 
                                                    hit->normal());
    }

    GTuple color_at(GRay& ray) {
        GIntersections i = intersect_world(ray);
        if(i.count()>0){
            GIntersection top = i.top();
            GHit hit = GHit(&top, &ray);
            return shade_hit(&hit);
        }
        return GTuple(0, 0, 0);
    }

private:
    GLight* fLight;
    std::vector<GObject*> fObjects;
};

#endif