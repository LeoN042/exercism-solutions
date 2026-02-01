#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    if (factors == NULL || number_of_factors == 0 || limit <= 1) {
        return 0;
    }
    int exist[limit];
    for (unsigned int i = 0; i < limit; i++) {
        exist[i] = 0;
    }
    unsigned int sum = 0;
    for (size_t i = 0; i < number_of_factors; i++) {
        if (factors[i] == 0) { continue; }
        for (int j = 1; j * factors[i] < limit; j++) {
            if (exist[j * factors[i]] == 0) {
                sum += j * factors[i];
            }
            
            exist[j * factors[i]] = 1;
        }
    }
    return sum;
}