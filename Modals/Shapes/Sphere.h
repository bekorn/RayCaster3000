// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_SPHERE_H
#define RAYCASTER3000_SPHERE_H


#include "Shape.h"

class Sphere : public Shape {
private:
    double radius;
public:
    Sphere(const Vector3 &position, double radius);

    Intersection * intersect_with(Ray ray) override;
};


#endif //RAYCASTER3000_SPHERE_H
