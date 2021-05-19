#ifndef GTuple_DEFINED
#define GTuple_DEFINED

#include <math.h>
 
#include "include/core/GMath.h"

class GTuple {

public:
    inline bool isPoint() { return G_FL_EQUAL(fW, 1.); }
    inline bool isVector() { return G_FL_EQUAL(fW, 0.);}

    GTuple() { }

    GTuple(float x, float y, float z) {
        this->fX = x;
        this->fY = y;
        this->fZ = z;
    }

    GTuple(float x, float y, float z, float w) {
        this->fX = x;
        this->fY = y;
        this->fZ = z;
        this->fW = w;
    }

    float magnitude();
    float length();
    float lengthSquared();
    GTuple normalize();
    
    GTuple reflect(GTuple&);
    float dot(GTuple&);
    GTuple cross(GTuple&);

    GTuple operator+(const GTuple&);
    GTuple operator-(const GTuple&);
    GTuple operator-();
    GTuple operator/(const float& rhs);
    GTuple operator*(const float& rhs);
    GTuple operator*(const GTuple& rhs);

    void setW(float w) { fW = w; }

    float x() const { return fX; }
    float y() const { return fY; }
    float z() const { return fZ; }
    float w() const { return fW; }
    
private:
    float fX, fY, fZ, fW;

};

#endif