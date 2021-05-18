#ifndef GMaterial_DEFINED
#define GMaterial_DEFINED

class GMaterial {
public:
    GMaterial() {
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

    GTuple color() { return fColor; }
    float ambient() { return fAmbient; }
    float diffuse() { return fDiffuse; }
    float specular() { return fSpecular; }
    float shininess() { return fShininess; }

private:
    GTuple fColor;
    float fAmbient, fDiffuse, fSpecular, fShininess;
};

#endif