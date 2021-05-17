#include "include/core/GSphere.h"
#include <iostream>
using namespace std;

bool GSphere::intersect(GRay& ray, float& t0, float& t1) {
    ray.transform(this->fMatrix.inverse());
    GTuple dir = ray.direction();
    GTuple ori = ray.origin();
    cout << dir.x() << " " << dir.y() << " " << dir.z() << "\n";
    cout << ori.x() << " " << ori.y() << " " << ori.z() << "\n";
    float t = (this->fOrigin - ray.origin()).dot(dir);
    GTuple p = ray.origin() + ray.direction() * t;
    float y = (this->fOrigin - p).length();
    // if(y > this->fRadius) {
    //    t0 = 0;
    //    t1 = 0;
    //    return false;
    // }
    float x = this->fRadius * this->fRadius - y*y;
    t0 = t - x;
    t1 = t + x;
    return true;
}

void GSphere::transform(GMatrix44 matrix) {
    this->fMatrix = matrix * this->fMatrix;
}