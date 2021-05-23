#include "include/core/GTuple.h"
#include "include/core/GWorld.h"
#include "include/core/GSphere.h"
#include "include/core/GLight.h"
#include "include/core/GCamera.h"

#include <iostream>

int main() {

    GWorld world = GWorld();
    GLight light = GLight(GTuple(-10, 10, -10), GTuple(1, 1, 1));
    world.add(light);

    GSphere floor = GSphere();
    floor.transform(GMatrix44::Scale(10, 0.01, 10));
    floor.material().setColor(GTuple(1, 0.9, 0.9));
    floor.material().setSpecular(0);
    world.add(&floor);

    GSphere left_wall = GSphere();
    GMatrix44 t = GMatrix44::Scale(10, 0.01, 10);
    t = GMatrix44::RotateX(1.5708) * t;
    t = GMatrix44::RotateY(-0.7853982) * t;
    t = GMatrix44::Translate(0, 0, 5) * t;
    left_wall.transform(t);
    left_wall.material().setColor(GTuple(1, 0.9, 0.9));
    left_wall.material().setSpecular(0);
    world.add(&left_wall);

    GSphere right_wall = GSphere();
    right_wall.transform(GMatrix44::Translate(0, 0, 5) *
                        GMatrix44::RotateY(0.7853982) *
                        GMatrix44::RotateX(1.570796) *
                        GMatrix44::Scale(10, 0.01, 10));
    right_wall.material().setColor(GTuple(1, 0.9, 0.9));
    right_wall.material().setSpecular(0);
    world.add(&right_wall);

    GSphere middle = GSphere();
    middle.transform(GMatrix44::Translate(-0.5, 1, 0.5));
    middle.material().setColor(GTuple(0.1, 1, 0.5));
    middle.material().setDiffuse(0.7);
    middle.material().setSpecular(0.3);
    world.add(&middle);

    GSphere right = GSphere();
    right.transform(GMatrix44::Translate(1.5, 0.5, -0.5) * 
                    GMatrix44::Scale(0.5, 0.5, 0.5));
    right.material().setColor(GTuple(0.5, 1, 0.1));
    right.material().setDiffuse(0.7);
    right.material().setSpecular(0.3);
    world.add(&right);

    GSphere left = GSphere();
    left.transform(GMatrix44::Translate(-1.5, 0.33, -0.75)*GMatrix44::Scale(0.33, 0.33, 0.33));
    left.material().setColor(GTuple(1, 0.8, 0.1));
    left.material().setDiffuse(0.7);
    left.material().setSpecular(0.3);
    world.add(&left);

    GCamera camera = GCamera(500, 250, 1.0471975512);
    camera.transform(GMatrix44::Orient(GTuple(0, 1.5, -5), 
                                        GTuple(0, 1, 0), 
                                        GTuple(0, 1, 0)));

    GCanvas out = camera.render(world);
    out.writeToFile("world.ppm");

}