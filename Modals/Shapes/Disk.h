#ifndef RAYCASTER3000_DISK_H
#define RAYCASTER3000_DISK_H

#include "Plane.h"

class Disk : public Plane {
private:
    double radius;
public:
    Disk(const Vector3 &position, const Vector3 &normal, double radius);

    Intersection * intersect_with(Ray ray) override;
};


#endif //RAYCASTER3000_DISK_H
