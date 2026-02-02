#include "eliuds_eggs.h"

unsigned int egg_count(int bin) {
    unsigned int count = 0;
    while (bin != 0) {
        count += bin & 1;
        bin = bin >> 1;
    }
    return count;
}