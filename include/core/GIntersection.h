#ifndef GIntersection_DEFINED
#define GIntersection_DEFINED

class GIntersection {

public: 
    GIntersection(float t, GSphere* object) {
        fT = t;
        fObject = object;
    }

private:
    float fT;
    GSphere* fObject;
};

#endif