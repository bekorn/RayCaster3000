// Created by Berk on 21.09.2017.
//

#include <iostream>
#include "Camera.h"

Camera::Camera() {}

Camera::Camera(const Vector3 &position, const Vector3 &look_at, const Vector3 &vertical_direction) :
        position(position),
        direction((look_at - position).unit_vector()),
        vertical_direction(vertical_direction)
//        view_width(view_width), view_height(view_height)
{
    this->horizontal_direction = this->vertical_direction.cross_product( this->direction ).unit_vector();
    this->vertical_direction = this->direction.cross_product( this->horizontal_direction );

//    std::cout << "Direction: ( "+ std::to_string(this->direction.x) +", "
//              + std::to_string(this->direction.y) +", "
//              + std::to_string(this->direction.z) +" )"
//            << std::endl;
//
//    std::cout << "Vertical Direction (up): ( "+ std::to_string(this->vertical_direction.x) +", "
//                 + std::to_string(this->vertical_direction.y) +", "
//                 + std::to_string(this->vertical_direction.z) +" )"
//              << std::endl;
//
//    std::cout << "Horizontal Direction (left): ( "+ std::to_string(this->horizontal_direction.x) +", "
//                 + std::to_string(this->horizontal_direction.y) +", "
//                 + std::to_string(this->horizontal_direction.z) +" )"
//              << std::endl;
}
