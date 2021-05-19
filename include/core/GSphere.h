#ifndef GSphere_DEFINED
#define GSphere_DEFINED

#include "include/core/GRay.h"
#include "include/core/GTuple.h"
#include "include/core/GMaterial.h"

class GSphere {
public:
    GSphere() { fMaterial = GMaterial(); fMatrix = GMatrix44(); }
    bool intersect(GRay&, float&, float&);
    void transform(GMatrix44 matrix);
    GTuple normal_at(GTuple& point);
    
    GMaterial& material() { return fMaterial; }
    void setMaterial(GMaterial material) { fMaterial = material; }

private:
    GMatrix44 fMatrix;
    GMaterial fMaterial;
};

#endif