#ifndef GStripePattern_DEFINED
#define GStripePattern_DEFINED

#include "include/core/GPattern.h"

class GStripePattern : public GPattern {
public:
    GStripePattern() { fFirst = GTuple(0, 0, 0); fSecond = GTuple(1, 1, 1); }
    
    GStripePattern(GTuple first, GTuple second) {
        fFirst = first;
        fSecond = second;
    }

    GTuple local_color_at(GTuple point) override;

private:
    GTuple fFirst, fSecond;
};

#endif