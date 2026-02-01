#include "binary.h"
#include <string.h>
#include <stdlib.h>

int convert(const char *input) {
    int len = strlen(input);
    int sum = 0;
    int square = 1;
    for (int i = len - 1; i >= 0; i--) {
        int digit = input[i] - '0';
        if (digit > 1 || digit < 0) {
            return -1;
        }
        sum += digit * square;
        square *= 2;
    }
    return sum;
}