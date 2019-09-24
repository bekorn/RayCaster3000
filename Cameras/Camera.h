// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_CAMERA_H
#define RAYCASTER3000_CAMERA_H

#include "../Primitives/Vector3.h"

class Camera {
public:
    Vector3 position, direction,
            horizontal_direction, vertical_direction;
    double view_width, view_height;

    Camera() = default;

    Camera(const Vector3 &position, const Vector3 &look_at, const Vector3 &vertical_direction);
};


#endif //RAYCASTER3000_CAMERA_H
