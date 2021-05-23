#include "include/core/GMaterial.h"

GTuple GMaterial::lighting(GLight* light, GTuple point, GTuple eyev, GTuple normalv) {
    GTuple effective_color = this->color() * light->intensity();
    GTuple lightv = (light->position() - point).normalize();
    GTuple ambient = effective_color * this->ambient();
    float light_dot_normal = lightv.dot(normalv);
    GTuple diffuse = GTuple(0, 0, 0, 0);
    GTuple specular = GTuple(0, 0, 0, 0);
    if(light_dot_normal >= 0) {
        diffuse = effective_color * this->diffuse() * light_dot_normal;
        GTuple reflectv = (-lightv).reflect(normalv);
        float reflect_dot_eye = reflectv.dot(eyev);
        if(reflect_dot_eye <= 0) { specular = GTuple(0, 0, 0); }
        else {
            float factor = pow(reflect_dot_eye, this->shininess());
            specular = light->intensity() * this->specular() * factor;
        }
    }
    return ambient + diffuse + specular;
}
