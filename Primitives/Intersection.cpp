// Created by Berk on 21.09.2017.
//

#include "Intersection.h"

Intersection::Intersection(double distance, const Vector3 &point, const Vector3 &normal, const Vector3 &reflection, Modal *modal) :
        distance(distance), point(point), normal(normal), reflection(reflection), modal(modal) {}
