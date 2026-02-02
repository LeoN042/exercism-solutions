#include "triangle.h"

bool is_triangle(triangle_t tri) {
    if (tri.a + tri.b > tri.c && tri.b + tri.c > tri.a && tri.c + tri.a > tri.b) {
        return true;
    }
    return false;
}
bool is_equilateral(triangle_t tri) {
    if (!is_triangle(tri)) {
        return false;
    }
    if (tri.a == tri.b && tri.b == tri.c) {
        return true;
    }
    return false;
}
bool is_isosceles(triangle_t tri) {
    if (!is_triangle(tri)) {
        return false;
    }
    if (tri.a == tri.b || tri.b == tri.c || tri.c == tri.a) {
        return true;
    }
    return false;
}
bool is_scalene(triangle_t tri) {
    if (!is_triangle(tri)) {
        return false;
    }
    if (is_equilateral(tri) || is_isosceles(tri)) {
        return false;
    }
    return true;
}