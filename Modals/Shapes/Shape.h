// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_SHAPE_H
#define RAYCASTER3000_SHAPE_H

#include "../../Primitives/Vector3.h"
#include "../../Primitives/Ray.h"
#include "../../Primitives/Intersection.h"
#include "../../Primitives/Color.h"

class Shape {
protected:
    Vector3 position;
public:
    explicit Shape(const Vector3 &position);
    virtual ~Shape() = default;

    virtual Intersection * intersect_with( Ray ray ) = 0;
};


#endif //RAYCASTER3000_SHAPE_H
