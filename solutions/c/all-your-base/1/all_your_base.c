#include "all_your_base.h"

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length) {
    int sum = 0;
    for (size_t i = 0; i < input_length; i++) {
        int mult = 1;
        for (size_t j = 0; j < input_length - i - 1; j++) {
            mult *= input_base;
        }
        sum += digits[i] * mult;
    }
    size_t k = 0;
    while (sum != 0) {
        for (int l = k - 1; l >= 0; l--) {
            digits[l+1] = digits[l];
        }
        
        digits[0] = sum % output_base;
        sum /= output_base;
        k++;
    }
    return k;
}
