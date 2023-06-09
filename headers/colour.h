#pragma once

#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"
#include <cassert>

void write_colour(FILE* ppm, colour pixel, int samples_per_pixel) {
    float r = pixel.x();
    float g = pixel.y();
    float b = pixel.z();

    // Dividing colour value by number of samples
    float scale = 1.0 / samples_per_pixel;
    r = sqrt(r*scale);
    g = sqrt(g*scale);
    b = sqrt(b*scale);

    // Writing output to file
    fprintf(ppm, "%d %d %d\n",
            static_cast<int>(256 * clamp(r, 0.0, 0.999)),
            static_cast<int>(256 * clamp(g, 0.0, 0.999)),
            static_cast<int>(256 * clamp(b, 0.0, 0.999))
    );
}

#endif