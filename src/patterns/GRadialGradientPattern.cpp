#include "src/patterns/GRadialGradientPattern.h"

GTuple GRadialGradientPattern::local_color_at(GTuple point) {
    float pos = fCount*(point).magnitude();
    float ratio = (pos-(int)(pos));
    float inv_ratio = 1. - ratio;
    return(fColors[((int)pos)%(fCount-1)] * inv_ratio + fColors[((int)pos)%(fCount-1)+1] * ratio);
}