#ifndef GIntersections_DEFINED
#define GIntersections_DEFINED

#include "include/core/GIntersection.h"

#include <vector>
#include <algorithm>


class GIntersections {
public:
    GIntersections() { 
        std::make_heap(fIntersections.begin(), fIntersections.end(), intersection_lt());
        fHit = false; 
    }

    void insert(GIntersection intersection) { 
        if(intersection.t() > 0) { fHit = true; }
        fIntersections.push_back(intersection);
        std::push_heap(fIntersections.begin(), fIntersections.end(), intersection_lt()); 
        fCount++; 
    }

    std::vector<GIntersection>* getIntersections() { 
        if( std::is_heap(fIntersections.begin(), fIntersections.end(), intersection_lt())){
            std::sort_heap(fIntersections.begin(), fIntersections.end(), intersection_lt());
        }

        return &fIntersections;
    }

    GIntersection top() { return this->getIntersections()->front(); }
    GIntersection at(int index) { assert(index < fCount); return this->getIntersections()->at(index); }

    int count() { return fCount; }
    bool hasHit() { return fHit; }

private:
    std::vector<GIntersection> fIntersections;
    int fCount = 0;
    bool fHit = false;
};

#endif