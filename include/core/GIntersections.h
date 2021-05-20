#ifndef GIntersections_DEFINED
#define GIntersections_DEFINED

#include "include/core/GIntersection.h"

#include <iostream>
#include <vector>


class GIntersections {
public:
    GIntersections(){}
    void insert(GIntersection intersection) { fIntersections.push_back(intersection); }
    std::vector<GIntersection>* getIntersections() { return &fIntersections; }
    void print() { std::cout << "Intersections {"; for(GIntersection i : this->fIntersections) { std::cout << "\n\t" << i.getT(); } std::cout << "\n};\n"; }
private:
    std::vector<GIntersection> fIntersections;
};

#endif