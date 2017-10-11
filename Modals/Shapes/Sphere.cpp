// Created by Berk on 21.09.2017.
//

#include "Sphere.h"


Sphere::Sphere(const Vector3 &position, double radius) : Shape(position), radius(radius) {}

Intersection * Sphere::intersect_with( Ray ray ) {

    //  |(A + tD) - C| = r solutions for t are the intersects

    double a, b, c, delta, distance,
            r = this->radius;
    Vector3 v = ray.origin - this->position,
            d = ray.direction;

    //  a*t^2 + b*t + c = 0
    a = d.x * d.x + d.y * d.y + d.z * d.z;
    b = 2 * v.dot_product(d);
    c = (v.x * v.x + v.y * v.y + v.z * v.z) - r * r;

    delta = b * b - 4 * a * c;

    if (delta < 0) {
        //  No Solution
        distance = 0;
    } else if (delta == 0) {
        //  One solution
        distance = fmax(0, -b / (2 * a));
    } else {
        //  Two solutions
        double s1 = (-b + sqrt(delta)) / (2 * a),
                s2 = (-b - sqrt(delta)) / (2 * a);

        // Smallest (nearest) solution is needed
        //  TODO: Find a smaller solution
        if (s1 > 0 && s1 < s2) {
            distance = s1;
        } else if (s2 > 0 && s2 < s1) {
            distance = s2;
        } else {
            distance = 0;
        }
    }


    if( distance >= 0.00001 ) {
        Vector3 normal = ((ray.origin + (ray.direction * distance)) - this->position).unit_vector();
        return new Intersection(
                distance,
                ray.origin + ( ray.direction * distance ),
                normal,
                ( ray.direction - (normal * 2.0 * normal.dot_product( ray.direction )) ).unit_vector(),
                nullptr);
    }
    else {
        return nullptr;
    }
}
