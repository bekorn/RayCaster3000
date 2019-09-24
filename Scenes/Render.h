// Created by Berk on 8.03.2019.
//

#ifndef RAYCASTER3000_RENDER_H
#define RAYCASTER3000_RENDER_H

#include "../Primitives/Color.h"

struct Render {
    Color *pixels;
    const int width, height;

    Render( int width, int height ) : width(width), height(height)
    {
        pixels = new Color[ this->width * this->height ];
    }

    ~Render()
    {
        delete[] pixels;
    }

    void set(int width, int height, const Color& color)
    {
        pixels[width + height * this->width] = color;
    }

    Color* get(int width, int height)
    {
        return &pixels[width + height * this->width];
    }
};


#endif //RAYCASTER3000_RENDER_H
