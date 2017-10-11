// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_MODAL_H
#define RAYCASTER3000_MODAL_H


#include "Shapes/Shape.h"
#include "Materials/Material.h"
#include "../Primitives/Intersection.h"

class Modal {
public:
    Shape *shape;
    Material *material;
    Modal(Shape *shape, Material *material);
    ~Modal();
    Intersection * intersect_with(Ray ray);
};


#endif //RAYCASTER3000_MODAL_H
