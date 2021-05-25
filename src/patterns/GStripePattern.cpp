#include "src/patterns/GStripePattern.h"
#include "include/core/GMath.h"

GTuple GStripePattern::local_color_at(GTuple point) {
    if(G_INT_ISODD((int)point.x())) {
        return this->fFirst;
    }
    return this->fSecond;
}
