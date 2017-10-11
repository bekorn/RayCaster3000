// Created by Berk on 22.09.2017.
//

#include "Light.h"

Light::Light(const Color &color, double intensity) :
        color(color), intensity( fmin(fmax(0.0,intensity),1.0) ) {}