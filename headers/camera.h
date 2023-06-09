#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "consts.h"

class camera {

public:
    camera() {
        float aspect_ratio = 16.0 / 9.0;
        float viewport_h = 2.0;
        float viewport_w = aspect_ratio * viewport_h;
        float focal_len = 1.0;

        origin = point3(0, 0, 0);
        horizontal = vec3(viewport_w, 0, 0);
        vertical = vec3(0, viewport_h, 0);
        lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_len);
    }

    ray get_ray(float u, float v) const {
        return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    }

private:
    point3 origin;              // Camera location
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;

};

#endif