// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_INTERSECTION_H
#define RAYCASTER3000_INTERSECTION_H


#include "Vector3.h"
//#include "../Modals/Modal.h"

class Modal;

class Intersection {
public:
    double distance;
    Vector3 point;
    Vector3 normal;
    Vector3 reflection;
    Modal *modal;

    Intersection(double distance, const Vector3 &point, const Vector3 &normal, const Vector3 &reflection, Modal *modal);
};


#endif //RAYCASTER3000_INTERSECTION_H
