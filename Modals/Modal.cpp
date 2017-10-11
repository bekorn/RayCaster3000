// Created by Berk on 21.09.2017.
//

#include "Modal.h"

Modal::Modal(Shape *shape, Material *material) : shape(shape), material(material) {}

Modal::~Modal() {
    delete this->material;
    delete this->shape;
}

Intersection * Modal::intersect_with(Ray ray) {
    Intersection *intersection = this->shape->intersect_with( ray );
    if( intersection != nullptr ) {
        intersection->modal = this;
    }
    return intersection;
}
