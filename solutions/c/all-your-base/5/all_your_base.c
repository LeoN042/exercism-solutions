#include "all_your_base.h"

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length) {
    if (input_base <= 1 || output_base <= 1) {
        return 0;
    }
    if (input_length == 0) {
        return 0;
    }

    uint64_t value = 0;
    for (size_t i = 0; i < input_length; ++i) {
        int8_t d = digits[i];
        if (d < 0 || d >= input_base) {
            return 0;
        }
        value = value * (uint64_t)input_base + (uint64_t)d;
    }

    int8_t tmp[DIGITS_ARRAY_SIZE] = {0};
    size_t out_len = 0;

    while (value > 0) {
        tmp[out_len++] = (int8_t)(value % (uint64_t)output_base);
        value /= (uint64_t)output_base;
    }
    for (size_t i = 0; i < out_len; ++i) {
        digits[i] = tmp[out_len - 1 - i];
    }

    return out_len;
}
