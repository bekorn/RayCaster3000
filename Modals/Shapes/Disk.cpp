#include "Disk.h"

Disk::Disk(const Vector3 &position, const Vector3 &normal, const double radius) : Plane(position, normal),
                                                                                  radius(radius) {

}

Intersection *Disk::intersect_with(Ray ray) {
    Intersection *intersection = Plane::intersect_with(ray);


    if (intersection != nullptr && (this->position - intersection->point).length < this->radius) {
        return intersection;
    }

    return nullptr;
}
