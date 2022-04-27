//#pragma once

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct vec3 {
    double e0;
    double e1;
    double e2;
};

typedef struct vec3 vec3;

vec3 vecinv(const vec3 in) {
    return (vec3) {-in.e0, -in.e1, -in.e2};
}

char *vecformat(const vec3 in) {
    char *buf = (char *) malloc(sizeof(char) * 100);
    sprintf(buf, "(%.2f, %.2f, %.2f)\0", in.e0, in.e1, in.e2);
    return buf;
}

int main() {
    vec3 a = {5, 3, 0};

    printf("A = %s\n", vecformat(a));
    printf("-A = %s\n", vecformat(vecinv(a)));
    return 0;
}