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
        fTransparency = 0.;
        fRefractiveIndex = 1.;
        fPattern = nullptr;
    }

    GMaterial(float ambient, float diffuse, float specular, 
              float shininess, float reflectivity, float transparency, float refractive_index) {
        fAmbient = ambient;
        fDiffuse = diffuse;
        fSpecular = specular;
        fShininess = shininess;
        fReflectivity = reflectivity;
        fTransparency = transparency;
        fRefractiveIndex = refractive_index;
        fPattern = nullptr;
    }

    GMaterial(float ambient, float diffuse, float specular, 
              float shininess, float reflectivity, float transparency,
              float refractive_index,  GPattern* pattern) {
        fAmbient = ambient;
        fDiffuse = diffuse;
        fSpecular = specular;
        fShininess = shininess;
        fReflectivity = reflectivity;
        fTransparency = transparency;
        fRefractiveIndex = refractive_index;
        fPattern = pattern;
    }

    void setColor(GTuple color) { fColor = color; }
    void setAmbient(float ambient) { fAmbient = ambient; }
    void setDiffuse(float diffuse) { fDiffuse = diffuse; }
    void setSpecular(float specular) { fSpecular = specular; } 
    void setShininess(float shininess) { fShininess = shininess; }
    void setPattern(GPattern* pattern) { fPattern = pattern; }
    void setReflectivity(float reflectivity) { fReflectivity = reflectivity; }
    void setTransparency(float transparency) { fTransparency = transparency; }
    void setRefractiveIndex(float refractive_index) { fRefractiveIndex = refractive_index; }

    GTuple color() { return fColor; }
    float ambient() { return fAmbient; }
    float diffuse() { return fDiffuse; }
    float specular() { return fSpecular; }
    float shininess() { return fShininess; }
    float reflectivity() { return fReflectivity; }
    GPattern* pattern() { return fPattern; }
    float transparency() { return fTransparency; }
    float refractive_index() { return fRefractiveIndex; }
    
    GTuple lighting(GObject* object, GLight* light, GTuple point, 
                    GTuple eyev, GTuple normalv, bool shadowed);

private:
    GTuple fColor;
    float fAmbient, fDiffuse, fSpecular, fShininess, fTransparency, fRefractiveIndex, fReflectivity;
    GPattern* fPattern;
};

#endif