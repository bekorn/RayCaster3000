// Created by Berk on 20.09.2017.
//

#include <cmath>
#include "Color.h"

Color::Color(double r, double g, double b) : r(r), g(g), b(b) {};

Color& Color::limit() {
    this->r = fmin( this->r, 255 );
    this->g = fmin( this->g, 255 );
    this->b = fmin( this->b, 255 );
    return *this;
}

Color Color::operator+( const Color &color ) {
    return Color(
            this->r + color.r,
            this->g + color.g,
            this->b + color.b
    );
}

Color Color::operator-( const Color &color ) {
    return Color(
            this->r - color.r,
            this->g - color.g,
            this->b - color.b
    );
}

Color Color::operator*( double n ) {
    return Color(
            this->r * n,
            this->g * n,
            this->b * n
    );
}

Color Color::operator/( double n ) {
    return Color(
            this->r / n,
            this->g / n,
            this->b / n
    );
}

Color Color::operator*( const Color &color ) {
    return Color(
            (this->r * color.r) / 255.0,
            (this->g * color.g) / 255.0,
            (this->b * color.b) / 255.0
    );
}

void Color::operator+=(const Color &color) {
    *this = *this + color;
}
