#include "darts.h"

uint8_t score(coordinate_t position) {
    float rad = position.x * position.x + position.y * position.y;
    if (rad <= 1.0F) {
        return 10;
    }
    if (rad <= 25.0F) {
        return 5;
    }
    if (rad <= 100.0F) {
        return 1;
    }
    return 0;
}