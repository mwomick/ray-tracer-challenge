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

private:
    float fT;
    GObject* fObject;
};

struct intersection_lt {
    bool operator()(GIntersection const& a, GIntersection const& b) const{
        return a.t() < b.t();
    }
};

#endif