#include "include/core/GTuple.h"
#include "include/core/GWorld.h"
#include "include/core/GSphere.h"
#include "include/core/GPlane.h"
#include "include/core/GLight.h"
#include "include/core/GCamera.h"

#include "src/patterns/GStripePattern.h"
#include "src/patterns/GLinearGradientPattern.h"
#include "src/patterns/GRadialGradientPattern.h"
#include "src/patterns/GCheckerPattern.h"

#include <iostream>

int main() {

    GWorld world = GWorld();
    GLight light = GLight(GTuple(-10, 10, -10), GTuple(1, 1, 1));
    world.add(light);

    GTuple colors[3] = {GTuple(1.0, 0.8, 0.1), GTuple(0.5, 1.0, 0.1), GTuple(0.1, 1, 0.5)};
    GLinearGradientPattern p0 = GLinearGradientPattern(colors, 3);
    GCheckerPattern p1 = GCheckerPattern(GTuple(0.1, 0.1, 0.1), GTuple(0.9, 0.9, 0.9));
    GStripePattern p2 = GStripePattern(GTuple(0.8, 0.5, 0.1), GTuple(0.1, 0.5, 1));
    p0.transform(GMatrix44::Scale(1, 1, 1));
    p1.transform(GMatrix44::Scale(.05, .05, .05));
    p2.transform(GMatrix44::Scale(.33, .33, .33));


    GPlane plane = GPlane();
    plane.material().setPattern(&p1);
    plane.material().setColor(GTuple(0.5, 0.5, 0.5));
    plane.material().setShininess(.65);
    plane.material().setSpecular(.65);
    plane.material().setReflectivity(0.5);
    world.add(&plane);

    GSphere middle = GSphere();
    middle.transform(GMatrix44::Translate(-0.5, 1, 0.5));
    middle.material().setColor(GTuple(0.1, 1, 0.5));
    middle.material().setDiffuse(0.7);
    middle.material().setSpecular(0.3);
    middle.material().setPattern(&p0);
    middle.material().setReflectivity(0.7);  
    world.add(&middle);

    GSphere right = GSphere();
    right.transform(GMatrix44::Translate(1.5, 0.5, -0.5) * 
                    GMatrix44::Scale(0.5, 0.5, 0.5) *
                    GMatrix44::RotateZ(1.570796));
    right.material().setColor(GTuple(0.5, 1, 0.1));
    right.material().setDiffuse(0.7);
    right.material().setSpecular(0.3);
    right.material().setPattern(&p2);
    right.material().setReflectivity(0.5);
    world.add(&right);

    GSphere left = GSphere();
    left.transform(GMatrix44::Translate(-1.5, 0.33, -0.75)*GMatrix44::Scale(0.33, 0.33, 0.33)
    *GMatrix44::RotateZ(1.570796));
    left.material().setColor(GTuple(0, 0, 0));
    left.material().setDiffuse(0.7);
    left.material().setSpecular(0.3);
    left.material().setReflectivity(0.5);
    left.material().setTransparency(1.0);
    left.material().setRefractiveIndex(1.52);
    world.add(&left);

    GCamera camera = GCamera(1000, 500, 1.0471975512);
    camera.transform(GMatrix44::Orient(GTuple(0, 1.5, -5), 
                                        GTuple(0, 1, 0), 
                                        GTuple(0, 1, 0)));

    GCanvas out = camera.render(world);
    out.writeToFile("world.ppm");

}