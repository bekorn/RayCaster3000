#include "Plane.h"

Plane::Plane(const Vector3 &position, const Vector3 &normal) : Shape(position),
                                                               normal(normal) {
    this->normal = this->normal.unit_vector();
}

Intersection *Plane::intersect_with(Ray ray) {
    double denominator = this->normal.dot_product(ray.direction);

    if (denominator != 0) {
        double distance = (this->position - ray.origin).dot_product(this->normal) / denominator;

        if (distance >= 0) {
            //TODO: Find a better way to fix acne
            Vector3 intersectionPoint = ray.origin + (ray.direction * distance) + this->normal / 1e10;

            return new Intersection(
                    distance,
                    intersectionPoint,
                    this->normal,
                    (ray.direction - (this->normal * 2.0 * this->normal.dot_product(ray.direction))).unit_vector(),
                    nullptr);
        }
    }

    return nullptr;
}