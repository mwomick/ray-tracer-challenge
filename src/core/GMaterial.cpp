#include "include/core/GMaterial.h"
#include "include/core/GObject.h"

GTuple GMaterial::lighting(GObject* o, GLight* light, GTuple point, 
                           GTuple eyev, GTuple normalv, bool shadowed) {

    GTuple color;
    if(this->pattern() != nullptr) {
        color = this->pattern()->color_at(o->matrix().inverse()*point);
    }
    else {
        color = this->color();
    }
    
    GTuple effective_color = color * light->intensity();
    GTuple lightv = (light->position() - point).normalize();
    GTuple ambient = effective_color * this->ambient();
    float light_dot_normal = lightv.dot(normalv);
    GTuple diffuse = GTuple(0, 0, 0, 0);
    GTuple specular = GTuple(0, 0, 0, 0);
    if(light_dot_normal >= 0 && !shadowed) {
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
