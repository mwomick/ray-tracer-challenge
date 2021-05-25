#include "src/patterns/GLinearGradientPattern.h"

GTuple GLinearGradientPattern::local_color_at(GTuple point) {
    float pos = abs(point.x());
    float ratio = (pos-(int)(pos));
    float inv_ratio = 1. - ratio;
    return(fColors[((int)pos)%(fCount-1)] * inv_ratio + fColors[((int)pos)%(fCount-1)+1] * ratio);
}