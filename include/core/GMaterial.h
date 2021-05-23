#ifndef GMaterial_DEFINED
#define GMaterial_DEFINED

#include "include/core/GTuple.h"
#include "include/core/GLight.h"

class GMaterial {
public:
    GMaterial() {
        fColor = GTuple(1, 1, 1);
        fAmbient = 0.1;
        fDiffuse = 0.9;
        fSpecular = 0.9;
        fShininess = 200.;
    }

    GMaterial(float ambient, float diffuse, float specular, float shininess) {
        fAmbient = ambient;
        fDiffuse = diffuse;
        fSpecular = specular;
        fShininess = shininess;
    }

    void setColor(GTuple color) { fColor = color; }
    void setAmbient(float ambient) { fAmbient = ambient; }
    void setDiffuse(float diffuse) { fDiffuse = diffuse; }
    void setSpecular(float specular) { fSpecular = specular; } 
    void setShininess(float shininess) { fShininess = shininess; }

    GTuple color() { return fColor; }
    float ambient() { return fAmbient; }
    float diffuse() { return fDiffuse; }
    float specular() { return fSpecular; }
    float shininess() { return fShininess; }

    GTuple lighting(GLight* light, GTuple point, 
                    GTuple eyev, GTuple normalv, bool shadowed);

private:
    GTuple fColor;
    float fAmbient, fDiffuse, fSpecular, fShininess;
};

#endif