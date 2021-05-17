#ifndef GIntersections_DEFINED
#define GIntersections_DEFINED

#include "include/core/GIntersection.h"

#include <vector>

class GIntersections {
public:
    GIntersections(){}
    void insert(GIntersection* intersection) { fIntersections.push_back(intersection); }
    std::vector<GIntersection*>* getIntersections() { return &fIntersections; }
private:
    std::vector<GIntersection*> fIntersections;
};

#endif