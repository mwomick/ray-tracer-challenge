#ifndef GWorld_DEFINED
#define GWorld_DEFINED

#include <vector>

#include "include/core/GSphere.h"
#include "include/core/GIntersections.h"
#include "include/core/GLight.h"
#include "include/core/GRay.h"
#include "include/core/GHit.h"


class GWorld {
public:
    GWorld() {
        
    }


    GIntersections intersect_world(GRay& ray);
    void add(GObject* object) { fObjects.push_back(object); }
    void add(GLight light) { fLight = light; }

    GTuple shade_hit(GHit* hit) {
        return hit->object()->material().lighting(&this->fLight, 
                                                    hit->point(), 
                                                    hit->eye(), 
                                                    hit->normal());
    }

    GTuple color_at(GRay& ray) {
        GIntersections i = intersect_world(ray);
        if(i.hasHit()){
            int x = 0;
            for(; i.at(x).t() < 0 && x < i.count(); x++) {
                continue;
            }
            GIntersection top = i.at(x);
            GHit hit = GHit(&top, &ray);
            GTuple t = shade_hit(&hit);
            return t;
        }
        return GTuple(0, 0, 0);
    }

    static GWorld* default_world() {
        GWorld* w = new GWorld();

        w->add(GLight(GTuple(-10, 10, -10), GTuple(1, 1, 1)));

        GSphere* s1 = new GSphere();
        s1->material().setColor(GTuple(0.8, 1.0, 0.6));
        s1->material().setDiffuse(0.7);
        s1->material().setSpecular(0.2);
        w->add(s1);

        GSphere* s2 = new GSphere();
        GMatrix44 m = GMatrix44::Scale(0.5, 0.5, 0.5);
        s2->transform(m);
        w->add(s2);

        return w;
    }

private:
    GLight fLight;
    std::vector<GObject*> fObjects;
};

#endif