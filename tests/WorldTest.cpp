#include "include/core/GWorld.h"
#include "include/core/GSphere.h"

int main() {
    GSphere sp = GSphere();
    GWorld w = GWorld();
    w.add(&sp);
    GRay r = GRay(GTuple(0, 0, 0), GTuple(1, 0, 0));
    w.intersect_world(r).print();
}