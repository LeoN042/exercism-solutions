#include "perfect_numbers.h"

kind classify_number(int n) {
    if (n <= 0) {
        return ERROR;
    }

    int sum = 0;

    if (n > 1) {
        sum = 1;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;

            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    if (sum == n) {
        return PERFECT_NUMBER;
    } else if (sum > n) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}