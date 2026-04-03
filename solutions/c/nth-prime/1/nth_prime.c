#include "nth_prime.h"

uint32_t nth(uint32_t n) {
    if (n == 0) {
        return 0; // There is no 0th prime
    }
    uint32_t arr[n];
    arr[0] = 2;
    arr[1] = 3;
    int flag = 0;
    for (uint32_t m = 2; m < n; m++) {
        arr[m] = 0;
    }
    for (uint32_t i = 2; i < n; i++) {
        int j = arr[i - 1] + 2;
        while (flag == 0) {
            for (int k = 2; k * k <= j; k++) {
                if (j % k == 0) {
                    j++;
                    flag = 0;
                    break;
                }
                else {
                    flag = 1;
                }
                
            }
        }
        arr[i] = j;
        flag = 0;
    }
    return arr[n - 1];
}