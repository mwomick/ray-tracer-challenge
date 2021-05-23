#ifndef GCanvas_DEFINED
#define GCanvas_DEFINED

#include <stdlib.h>

#include "include/core/GTuple.h"

class GCanvas {

public:
    GTuple* pixels() const { return fPixels; }

    GCanvas(int width, int height) {
        fWidth = width;
        fHeight = height;
        fPixels = (GTuple*)malloc(fHeight*fWidth*sizeof(GTuple));
    }
    
    GTuple* getAddr(int x, int y) const {
        return this->pixels() + x + y * fWidth;
    }

    void blit(int x, int y, GTuple& color);
    void blitRow(int x, int y, int size, GTuple& color);
    bool writeToFile(const char[]);

private:
    int fHeight, fWidth;
    GTuple* fPixels;

};

#endif