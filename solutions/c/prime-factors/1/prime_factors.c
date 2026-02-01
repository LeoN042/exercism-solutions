#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
    if (n <= 1) { return 0; }
    size_t j = 0;
    for (uint64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors[j++] = i;
            n /= i;
            i--;
        }
    }
    factors[j] = n;
    j++;
    return j;
}