#include "include/core/GSphere.h"
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

int GSphere::local_intersect(GRay& ray, GIntersections& dst) {
    float a = ray.direction().lengthSquared();
    GTuple sp_to_ra = ray.origin();
    float b = 2 * ray.direction().dot(sp_to_ra);
    float c = sp_to_ra.lengthSquared() - 1;
    float disc = b*b - 4*a*c;
    if(disc < 0) { return 0; }
    float t0 = (-b - sqrt(disc)) / (2 * a);
    float t1 = (-b + sqrt(disc)) / (2 * a);
    GIntersection i0 = GIntersection(t0, this);
    GIntersection i1 = GIntersection(t1, this);
    dst.insert(i0);
    dst.insert(i1);
    return 2;
}

GTuple GSphere::local_normal_at(GTuple& point)
{
    return point.normalize();
}