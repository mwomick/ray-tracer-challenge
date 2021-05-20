#ifndef GIntersection_DEFINED
#define GIntersection_DEFINED

class GObject;

class GIntersection {

public: 
    GIntersection(float t, GObject* object) {
        fT = t;
        fObject = object;
    }

    float getT() { return fT; }

private:
    float fT;
    GObject* fObject;
};

#endif