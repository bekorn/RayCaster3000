// Created by Berk on 22.09.2017.
//

#ifndef RAYCASTER3000_LIGHT_H
#define RAYCASTER3000_LIGHT_H


#include "../Primitives/Vector3.h"
#include "../Primitives/Color.h"

class Light {
public:
    Color color;
    double intensity;

    Light(const Color &color, double intensity);
};


#endif //RAYCASTER3000_LIGHT_H
