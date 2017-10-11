// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_MATERIAL_H
#define RAYCASTER3000_MATERIAL_H


#include "../../Primitives/Color.h"

class Material {
public:
    Color color;
    double ambient_reflectance;
    double diffuse_reflectance;
    double specular_reflectance;
    double mirror_reflectance;

    Material(const Color &color, double ambient_reflectance, double diffuse_reflectance, double specular_reflectance,
             double mirror_reflectance);
};


#endif //RAYCASTER3000_MATERIAL_H
