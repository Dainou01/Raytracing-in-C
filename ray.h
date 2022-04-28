#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "vec3.h"

struct ray {
    point3 orig;
    vec3 dir;
};

typedef struct ray ray;

point3 *at(const ray *ray, const double t) {
    return add(&ray->orig, constmul(&ray->dir, t));
}

#endif //RAYTRACING_RAY_H
