#ifndef GIntersections_DEFINED
#define GIntersections_DEFINED

#include "include/core/GIntersection.h"

#include <iostream>
#include <vector>
#include <algorithm>


class GIntersections {
public:
    GIntersections(){}

    void insert(GIntersection intersection) { 
        fIntersections.push_back(intersection);
        std::push_heap(fIntersections.begin(), fIntersections.end()); 
        fCount++; 
    }

    std::vector<GIntersection>* getIntersections() { 
        std::reverse(fIntersections.begin(), fIntersections.end());
        return &fIntersections; 
    }

    void print() { 
        std::cout << "Intersections {"; 
        for(GIntersection i : *this->getIntersections()) {
             std::cout << "\n\t" << i.getT(); 
        } 
        std::cout << "\n};\n"; 
    }

    int count() { return fCount; }
private:
    std::vector<GIntersection> fIntersections;
    int fCount;
};

#endif