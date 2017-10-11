// Created by Berk on 21.09.2017.
//

#include "Material.h"

Material::Material(const Color &color, double ambient_reflectance, double diffuse_reflectance,
                   double specular_reflectance, double mirror_reflectance) :
        color(color),
        ambient_reflectance(ambient_reflectance),
        diffuse_reflectance(diffuse_reflectance),
        specular_reflectance(specular_reflectance),
        mirror_reflectance(mirror_reflectance) {}
