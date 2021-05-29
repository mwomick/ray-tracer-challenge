#ifndef GCheckerPattern_DEFINED
#define GCheckerPattern_DEFINED

#include "include/core/GPattern.h"

class GCheckerPattern : public GPattern {
public:    

    GCheckerPattern() {
    }

    GCheckerPattern(GTuple a, GTuple b) {
        fColorA = a;
        fColorB = b;
    }

    GTuple local_color_at(GTuple point) override;

private:
    GTuple fColorA = GTuple(0, 0, 0);
    GTuple fColorB = GTuple(1, 1, 1); 
};

#endif
