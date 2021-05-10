#ifndef GMatrix44_DEFINED
#define GMatrix44_DEFINED

#include "include/core/GMath.h"

class GMatrix44 {
public:
    GMatrix44() : fMat {1, 0, 0, 0, 
                        0, 1, 0, 0, 
                        0, 0, 1, 0, 
                        0, 0, 0, 1} 
    {}
    
    GMatrix44(float a, float b, float c, float d,
              float e, float f, float g, float h,  
              float i, float j, float k, float l,
              float m, float n, float o, float p) {
        fMat[ 0] = a;   fMat[ 1] = b;    fMat[ 2] = c;    fMat[ 3] = d;
        fMat[ 4] = e;   fMat[ 5] = f;    fMat[ 6] = g;    fMat[ 7] = h;
        fMat[ 8] = i;   fMat[ 9] = j;    fMat[10] = k;    fMat[11] = l;
        fMat[12] = m;   fMat[13] = n;    fMat[14] = o;    fMat[15] = p;
    }

    float operator[](int index) {
        return fMat[index];
    }

    GMatrix44 operator*(const GMatrix44& rhs) {
        float matrix[16];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                matrix[j+(i<<2)] = this->fMat[(i<<2)] * rhs.fMat[j] +
                                   this->fMat[(i<<2)+1] * rhs.fMat[j+4] +
                                   this->fMat[(i<<2)+2] * rhs.fMat[j+8] +
                                   this->fMat[(i<<2)+3] * rhs.fMat[j+12];
            }
        }
        return GMatrix44(matrix[0], matrix[1], matrix[2], matrix[3], 
                         matrix[4], matrix[5], matrix[6], matrix[7],
                         matrix[8], matrix[9], matrix[10], matrix[11], 
                         matrix[12], matrix[13], matrix[14], matrix[15]);
    }

private:
    float fMat[16]; 
};

#endif

#ifndef GMatrix33_DEFINED
#define GMatrix33_DEFINED

class GMatrix33 {
public:
 
    GMatrix33() : fMat {1, 0, 0, 
                        0, 1, 0,
                        0, 0, 1} 
    {}
    
    GMatrix33(float a, float b, float c, 
              float d, float e, float f, 
              float g, float h, float i) {
        fMat[0] = a;   fMat[1] = b;    fMat[2] = c;
        fMat[3] = d;   fMat[4] = e;    fMat[5] = f;
        fMat[6] = g;   fMat[7] = h;    fMat[8] = i;
    }

private:
    float fMat[9]; 
};

#endif

#ifndef GMatrix22_DEFINED
#define GMatrix22_DEFINED

class GMatrix22 {
public:
 
    GMatrix22() : fMat {1, 0, 
                        0, 1}
    {}
    
    GMatrix22(float a, float b, float c, float d) {
        fMat[0] = a;   fMat[1] = b;    
        fMat[2] = c;   fMat[3] = d;
    }

private:
    float fMat[4]; 
};

#endif