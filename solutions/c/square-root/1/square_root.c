#include "square_root.h"

unsigned int square_root(unsigned int input) {
    if (input < 2) return input;
    unsigned int left = 2;
    unsigned int right = input / 2;
    while (left <= right) {
        unsigned int mid = left + ((right - left) >> 1);
        if (mid * mid == input) {
            return mid;
        }
        else if (mid * mid > input) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}