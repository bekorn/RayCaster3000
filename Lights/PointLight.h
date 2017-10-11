// Created by Berk on 03.10.2017.
//

#ifndef RAYCASTER3000_POINTLIGHT_H
#define RAYCASTER3000_POINTLIGHT_H


#include "Light.h"

class PointLight : public Light {
public:
    Vector3 position;

    PointLight(const Color &color, double intensity, const Vector3 &position);
};


#endif //RAYCASTER3000_POINTLIGHT_H
