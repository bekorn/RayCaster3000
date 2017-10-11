// Created by Berk on 28.09.2017.
//

#ifndef RAYCASTER3000_SETTINGS_H
#define RAYCASTER3000_SETTINGS_H

#include "../Primitives/Color.h"

class Settings {
public:
    int resolution_width;
    int resolution_height;
    double resolution_ratio;
    double field_of_view;
    Color background_color;
    int anti_alias;
    int bounce_limit;

    Settings() {};
    Settings(int resolution_width, int resolution_height, const Color &background_color, int anti_alias, int bounce_limit) :
            resolution_width(resolution_width), resolution_height(resolution_height),
            resolution_ratio( (double)resolution_width / (double)resolution_height ),
            field_of_view( atan(resolution_ratio) ),
            background_color(background_color),
            anti_alias(anti_alias),
            bounce_limit(bounce_limit) {}
};

#endif //RAYCASTER3000_SETTINGS_H
