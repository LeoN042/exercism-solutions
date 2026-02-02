#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int i = 0;
    int count = 0;
    while (lhs[i] != '\0') {
        if (lhs[i] != rhs[i]) {
            count++;
        }
        i++;
    }
    if (rhs[i] != '\0') {
        return -1;
    }
    return count;
}