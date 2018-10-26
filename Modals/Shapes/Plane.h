#ifndef RAYCASTER3000_PLANE_H
#define RAYCASTER3000_PLANE_H

#include "Shape.h"
#include "math.h"

class Plane : public Shape {
private:
    Vector3 normal;
public:
    Plane(const Vector3 &position, const Vector3 &normal);

    Intersection * intersect_with(Ray ray) override;
};


#endif //RAYCASTER3000_PLANE_H
