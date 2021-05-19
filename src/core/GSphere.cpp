#include "include/core/GSphere.h"
#include <iostream>
using namespace std;

/* bool GSphere::intersect(GRay& ray, float& t0, float& t1) {
    ray = ray.transform(this->fMatrix.inverse());
    GTuple rd = ray.direction();
    GTuple ro = ray.origin();
    float t = (GTuple(0,0,0)-ro).dot(rd);
    GTuple p = ray.position(t);
    float y = p.length();
    // if(y > 1) { return false; }
    float x = 1 - y*y;
    t0 = t - x;
    t1 = t + x;
    return true;
}
 */
 
bool GSphere::intersect(GRay& ray, float& t0, float& t1) {
    GRay r_n = ray.transform(this->fMatrix.inverse());
    float a = r_n.direction().lengthSquared();
    GTuple sp_to_ra = r_n.origin();
    float b = 2 * r_n.direction().dot(sp_to_ra);
    float c = sp_to_ra.lengthSquared() - 1;
    float disc = b*b - 4*a*c;
    if(disc < 0) { return false; }
    t0 = (-b - sqrt(disc)) / (2 * a);
    t1 = (-b + sqrt(disc)) / (2 * a);
    return true;
}

GTuple GSphere::normal_at(GTuple& point) {
    GTuple obj_normal = fMatrix.inverse() * point;
    GTuple world_normal = fMatrix.inverse().transpose() * obj_normal;
    world_normal.setW(0);
    return world_normal.normalize();
}

void GSphere::transform(GMatrix44 matrix) {
    this->fMatrix = matrix * this->fMatrix;
}