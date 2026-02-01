#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit == 0 || limit == 1) { return 0; }
    size_t count = 0;
    uint32_t mark[limit + 1];
    for (uint32_t k = 0; k < limit + 1; k++) {
        mark[k] = 0;
    }
    for (uint32_t i = 2; i <= limit; i++) {
        if (count < max_primes && mark[i] == 0) {
            primes[count] = i;
            count++;
            for (uint32_t j = i; j <= limit; j += i) {
                mark[j] = 1;
                
            }
        }
    }
    return count;
}