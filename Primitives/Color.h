// Created by Berk on 20.09.2017.
//

#ifndef RAYCASTER3000_PIXEL_H
#define RAYCASTER3000_PIXEL_H


#include <cstdint>

class Color {
public:
    double r, g, b;
    Color();
    Color(double r, double g, double b);
    Color& limit();
    Color operator+( const Color &color );
    void operator+=( const Color &color );
    Color operator-( const Color &color );
    Color operator*( double n );
    Color operator/( double n );
    Color operator*( const Color &color );
};


#endif //RAYCASTER3000_PIXEL_H
