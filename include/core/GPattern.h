#ifndef GPattern_DEFINED
#define GPattern_DEFINED

#include "include/core/GTuple.h"
#include "include/core/GMatrix.h"


class GPattern {
public:
    enum TileMode { kClamp, 
           kRepeat, 
           kMirror,
    };

    GTuple color_at(GTuple point) { 
        return local_color_at(this->fMatrix.inverse() * point);
    }

    void transform(GMatrix44 matrix) { fMatrix = matrix * fMatrix; }

    virtual GTuple local_color_at(GTuple point) { return GTuple(0, 0, 0); }
protected:
    GMatrix44 fMatrix = GMatrix44();
};

#endif