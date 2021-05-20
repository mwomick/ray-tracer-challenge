#ifndef GIntersection_DEFINED
#define GIntersection_DEFINED

class GObject;


class GIntersection {

public: 
    GIntersection(float t, GObject* object) {
        fT = t;
        fObject = object;
    }

    float t() const { return fT; }
    GObject* object() const { return fObject; }

    bool operator <(const GIntersection& b) const { return this->t() < b.t(); }
private:
    float fT;
    GObject* fObject;
};


#endif