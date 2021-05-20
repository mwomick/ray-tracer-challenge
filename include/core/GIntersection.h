#ifndef GIntersection_DEFINED
#define GIntersection_DEFINED

class GObject;


class GIntersection {

public: 
    GIntersection(float t, GObject* object) {
        fT = t;
        fObject = object;
    }

    float getT() const { return fT; }

    bool operator <(const GIntersection& b) const { return this->fT < b.getT(); }
private:
    float fT;
    GObject* fObject;
};


#endif