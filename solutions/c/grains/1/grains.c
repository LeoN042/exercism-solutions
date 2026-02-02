#include "grains.h"

uint64_t square(uint8_t index) {
    if (index == 1) {
        return 1;
    }
    return square(index - 1) * 2;
}

uint64_t total(void) {
    return square(65) - 1;
}