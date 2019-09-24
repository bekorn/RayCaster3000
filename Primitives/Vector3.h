// Created by Berk on 20.09.2017.
//

#ifndef RAYCASTER3000_VECTOR3_H
#define RAYCASTER3000_VECTOR3_H

#include <cmath>
#include "../Debug/LeakCounter.h"

struct Vector3 : Debug::LeakCounter<Vector3&> {

    const static Vector3 unit_x, unit_y, unit_z;

    double x, y, z, length;

    Vector3() = default;

    explicit Vector3(double x, double y, double z);

    Vector3 operator+(const Vector3 &v3) const;

    Vector3 operator-(const Vector3 &v3) const;

    Vector3 operator*(double n) const;

    Vector3 operator/(double n) const;

    Vector3 unit_vector() const;

    Vector3 cross_product(const Vector3 &v3) const;

    double dot_product(const Vector3 &v3) const;
};


#endif //RAYCASTER3000_VECTOR3_H
