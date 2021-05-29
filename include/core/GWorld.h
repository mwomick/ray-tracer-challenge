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
    GWorld() {}

    GIntersections intersect_world(GRay& ray);
    void add(GObject* object) { fObjects.push_back(object); }
    void add(GLight light) { fLight = light; }

    GTuple shade_hit(GHit* hit, int remaining) {
        GTuple surface = hit->object()->material().lighting(hit->object(), 
                                                    &this->fLight, 
                                                    hit->over(), 
                                                    hit->eye(), 
                                                    hit->normal(), 
                                                    isShadowed(hit->over()));

        GTuple reflected = reflected_color(hit, remaining);
        GTuple refracted = refracted_color(hit, remaining);

        return surface + reflected + refracted;
    }

    GTuple reflected_color(GHit* hit, int remaining) {
        if(hit->object()->material().reflectivity() == 0 || remaining == 0) { return GTuple(0, 0, 0); }
        GRay ray = hit->reflect();
        GTuple color = color_at(ray, remaining-1);
        return color * hit->object()->material().reflectivity();
    }

    GTuple refracted_color(GHit* hit, int remaining) {
        if(hit->object()->material().transparency() == 0 || remaining == 0) {
            return GTuple(0, 0, 0);
        }
        float n_ratio = hit->n1() / hit->n2();
        GTuple normal = hit->normal(); // TODO: normal() should return reference instead of GTuple?
        float cos_i = hit->eye().dot(normal);
        float sin2_t = n_ratio * n_ratio * (1. - cos_i*cos_i);
        if(sin2_t > 1) { return GTuple(0, 0, 0); }
        float cos_t = sqrt(1.0 - sin2_t);
        GTuple dir = hit->normal() * (n_ratio * cos_i - cos_t) - hit->eye() * n_ratio;
        GRay ray = GRay(hit->under(), dir);
        GTuple color = color_at(ray, remaining-1) * hit->object()->material().transparency();
        return color;
    }

    GTuple color_at(GRay& ray, int remaining) {
        GIntersections i = intersect_world(ray);
        if(i.hasHit()){
            int x = 0;
            
            float n1 = 1.0;
            float n2 = 1.0;

            std::vector<GObject*> containers;

            for(; x < i.count(); x++) {
                // if it is a hit, set n1 to the most recently unexited object's refractive index
                if(i.at(x).t() >= 0) {
                    if(!containers.empty()) {
                        n1 = containers.back()->material().refractive_index();
                    }
                }
                // if the object has been entered and we encounter an intersection, the intersection is an exit
                auto it = std::find(containers.begin(), containers.end(), i.at(x).object());
                if(it != containers.end()) {
                    // an object has been exited -> we don't need it anymore
                    containers.erase(it);
                }
                else {
                    // we enter an object; append it to containers
                    containers.push_back(i.at(x).object());
                }
                // if it's a hit, now we know what n2 should be
                if(i.at(x).t() >= 0) {
                    if(!containers.empty()) {
                        n2 = containers.back()->material().refractive_index();
                    }
                    break;
                }
            }

            GIntersection intersection = i.at(x);
            GHit hit = GHit(&intersection, &ray);
            hit.setRefraction(n1, n2);

            GTuple t = shade_hit(&hit, remaining);
            return t;
        }
        return GTuple(0, 0, 0);
    }

    bool isShadowed(GTuple point) {
        GTuple pt_to_lt = this->fLight.position() - point;
        float dist = pt_to_lt.magnitude();
        GRay shadow_ray = GRay(point, pt_to_lt.normalize());
        GIntersections i = intersect_world(shadow_ray);
        if(i.hasHit()) {
            int x = 0;
            for(; i.at(x).t() < 0 && x < i.count(); x++) {
                continue;
            }
            GIntersection top = i.at(x);
            GHit hit = GHit(&top, &shadow_ray);
            if(hit.t() < dist) {
                return true;
            }
        }
        return false;
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