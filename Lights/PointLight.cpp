// Created by Berk on 03.10.2017.
//

#include "PointLight.h"

PointLight::PointLight(const Color &color, double intensity, const Vector3 &position) :
        Light(color, intensity),
        position(position) {}
