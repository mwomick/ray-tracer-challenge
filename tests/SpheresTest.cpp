#include <iostream>

#include "include/core/GSphere.h"
#include "include/core/GRay.h"
#include "include/core/GTuple.h"
#include "include/core/GIntersection.h"
#include "include/core/GIntersections.h"

using namespace std;

int main() {
    GTuple ro = GTuple(0, 0, -5);
    GTuple rd = GTuple(0, 0, 1);
    GRay origin = GRay(ro, rd);
    GSphere sphere = GSphere();
    float t0, t1;
    
    GMatrix44 matrix = GMatrix44::Scale(2, 2, 2);
    sphere.transform(matrix);
    sphere.intersect(origin, t0, t1);
    GIntersection a = GIntersection(t0, &sphere);
    GIntersection b = GIntersection(t1, &sphere);
    GIntersections intersections = GIntersections();
    intersections.insert(&a);
    intersections.insert(&b);
    cout << t0 << " " << t1 << "\n";

}