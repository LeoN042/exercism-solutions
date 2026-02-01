#include "collatz_conjecture.h"

int steps(int start) {
    if (start <= 0) {
        return -1;  // invalid input
    }
    
    int count = 0;
    long n = start;
    while (n != 1) {
        if ((n & 1) == 0) {
            n /=2;
            count++;
        }
        else {
            n = n * 3 + 1;
            count++;
        }
    }
    return count;
}