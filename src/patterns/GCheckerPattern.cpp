#include "src/patterns/GCheckerPattern.h"

GTuple GCheckerPattern::local_color_at(GTuple point) {
    int x = abs(point.x());
    int y = abs(point.y());
    int z = abs(point.z());
    if((x+y+z) % 2 == 0) {
        return this->fColorA;
    }
    else {
        return this->fColorB;
    }
}