// Created by Berk on 03.10.2017.
//

#ifndef RAYCASTER3000_AMBIENTLIGHT_H
#define RAYCASTER3000_AMBIENTLIGHT_H


#include "Light.h"

class AmbientLight : public Light {
public:
    AmbientLight(const Color &color, double intensity );
};


#endif //RAYCASTER3000_AMBIENTLIGHT_H
