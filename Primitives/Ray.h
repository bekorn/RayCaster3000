// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_RAY_H
#define RAYCASTER3000_RAY_H


#include "Vector3.h"

struct Ray : public Debug::LeakCounter<Ray> {

    const Vector3 origin, direction;

    explicit Ray(const Vector3 &origin, const Vector3 &direction);
};


#endif //RAYCASTER3000_RAY_H
