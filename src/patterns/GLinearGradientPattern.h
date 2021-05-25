#ifndef GLinearGradientPattern_DEFINED
#define GLinearGradientPattern_DEFINED

#include "include/core/GPattern.h"

class GLinearGradientPattern : public GPattern {
public:
    // GGradientPattern() { fFirst = GTuple(0, 0, 0); fSecond = GTuple(1, 1, 1); }
    
    GLinearGradientPattern(GTuple* dst, int count) {
        fCount = count;
        fColors = dst;
    }

    GTuple local_color_at(GTuple point) override;

private:
    int fCount;
    GTuple* fColors;
};

#endif