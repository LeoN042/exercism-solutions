#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
    int sum = 0;
    int temp = candidate;
    int digit = 0;
    int rem[20] = {0};
    while (candidate != 0) {
        rem[digit] = candidate % 10;
        digit++;
        candidate /= 10;
    }
    for (int j = 0; j < digit; j++) {
        int p = 1;
        for (int i = 0; i < digit; i++) {
            p *= rem[j];
        }
        sum += p;
    }
    return sum == temp;
}