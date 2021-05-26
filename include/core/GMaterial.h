#ifndef GMaterial_DEFINED
#define GMaterial_DEFINED

// #include "include/core/GObject.h"
#include "include/core/GTuple.h"
#include "include/core/GLight.h"
#include "include/core/GPattern.h"

class GObject;

class GMaterial {
public:
    GMaterial() {
        fColor = GTuple(1, 1, 1);
        fAmbient = 0.1;
        fDiffuse = 0.9;
        fSpecular = 0.9;
        fShininess = 200.;
        fReflectivity = 0.;
        fPattern = nullptr;
    }

    GMaterial(float ambient, float diffuse, float specular, float shininess, float reflectivity) {
        fAmbient = ambient;
        fDiffuse = diffuse;
        fSpecular = specular;
        fShininess = shininess;
        fReflectivity = reflectivity;
        fPattern = nullptr;
    }

    GMaterial(float ambient, float diffuse, float specular, 
              float shininess, float reflectivity, GPattern* pattern) {
        fAmbient = ambient;
        fDiffuse = diffuse;
        fSpecular = specular;
        fShininess = shininess;
        fReflectivity = reflectivity;
        fPattern = pattern;
    }

    void setColor(GTuple color) { fColor = color; }
    void setAmbient(float ambient) { fAmbient = ambient; }
    void setDiffuse(float diffuse) { fDiffuse = diffuse; }
    void setSpecular(float specular) { fSpecular = specular; } 
    void setShininess(float shininess) { fShininess = shininess; }
    void setPattern(GPattern* pattern) { fPattern = pattern; }
    void setReflectivity(float reflectivity) { fReflectivity = reflectivity; }
    
    GTuple color() { return fColor; }
    float ambient() { return fAmbient; }
    float diffuse() { return fDiffuse; }
    float specular() { return fSpecular; }
    float shininess() { return fShininess; }
    float reflectivity() { return fReflectivity; }
    GPattern* pattern() { return fPattern; }

    GTuple lighting(GObject* object, GLight* light, GTuple point, 
                    GTuple eyev, GTuple normalv, bool shadowed);

private:
    GTuple fColor;
    float fAmbient, fDiffuse, fSpecular, fShininess, fReflectivity;
    GPattern* fPattern;
};

#endif