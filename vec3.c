#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct vec3 {
    double x;
    double y;
    double z;
};

typedef struct vec3 vec3;
typedef vec3 point;
typedef vec3 color;

void printvec(FILE *restrict stream, const vec3 a) {
    fprintf(stream, "%f %f %f", a.x, a.y, a.z);
}

char *formatvec(const vec3 *a, char *buf) {
    sprintf(buf, "(%.2f, %.2f, %.2f)", a->x, a->y, a->z);
    return buf;
}

vec3 *vecinv(const vec3 *a) {
    return &(vec3) {-a->x, -a->y, -a->z};
}

vec3 *addeq(vec3 *a, const vec3 *b) {
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
    return a;
}

vec3 *subeq(vec3 *a, const vec3 *b) {
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
    return a;
}

vec3 *muleq(vec3 *a, const double t) {
    a->x *= t;
    a->y *= t;
    a->z *= t;
    return a;
}

vec3 *diveq(vec3 *a, const double t) {
    return muleq(a, 1 / t);
}

vec3 *add(const vec3 *a, const vec3 *b) {
    vec3 *v = (vec3 *) malloc(sizeof(vec3));
    v->x = a->x + b->x;
    v->y = a->y + b->y;
    v->z = a->z + b->z;
    return v;
}

vec3 *sub(const vec3 *a, const vec3 *b) {
    vec3 *v = (vec3 *) malloc(sizeof(vec3));
    v->x = a->x - b->x;
    v->y = a->y - b->y;
    v->z = a->z - b->z;
    return v;
}

vec3 *mul(const vec3 *a, const vec3 *b) {
    vec3 *v = (vec3 *) malloc(sizeof(vec3));
    v->x = a->x * b->x;
    v->y = a->y * b->y;
    v->z = a->z * b->z;
    return v;
}

vec3 *constmul(const vec3 *a, const double t) {
    vec3 *v = (vec3 *) malloc(sizeof(vec3));
    v->x = a->x * t;
    v->y = a->y * t;
    v->z = a->z * t;
    return v;
}

vec3 *constdiv(const vec3 *a, const double t) {
    vec3 *v = (vec3 *) malloc(sizeof(vec3));
    v->x = a->x / t;
    v->y = a->y / t;
    v->z = a->z / t;
    return v;
}

vec3 *cross(const vec3 *a, const vec3 *b) {
    vec3 *v = (vec3 *) malloc(sizeof(vec3));
    v->x = a->y * b->z - a->z * b->y;
    v->y = a->z * b->x - a->x * b->z;
    v->z = a->x * b->y - a->y * b->x;
    return v;
}

double dot(const vec3 *a, const vec3 *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

double length_squared(const vec3 *a) {
    return a->x * a->x + a->y * a->y + a->z * a->z;
}

double length(const vec3 *a) {
    return sqrt(length_squared(a));
}

vec3 *normalize(vec3 *a) {
    return diveq(a, length(a));
}