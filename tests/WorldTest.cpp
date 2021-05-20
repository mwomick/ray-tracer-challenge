#include "include/core/GTuple.h"
#include "include/core/GWorld.h"
#include "include/core/GSphere.h"
#include "include/core/GLight.h"

int main() {
    GSphere sp1 = GSphere();
    GSphere sp2 = GSphere();
    GMatrix44 m = GMatrix44::Scale(0.5, 0.5, 0.5);
    sp2.transform(m);
    GWorld w = GWorld();
    GLight l = GLight(GTuple(-10, 10, -10), GTuple(1, 1, 1));
    w.add(&sp1);
    w.add(&sp2);
    w.add(&l);
    GRay r = GRay(GTuple(0, 0, -5), GTuple(0, 0, 1));
    w.intersect_world(r).print();
}