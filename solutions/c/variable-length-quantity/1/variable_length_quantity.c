#include "variable_length_quantity.h"

#include <stdint.h>
#include <stddef.h>

#define VLQ_CONT 0x80
#define VLQ_DATA 0x7F

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
    if (output == NULL) return -1;
    if (integers_len > 0 && integers == NULL) return -1;

    size_t out_len = 0;

    for (size_t k = 0; k < integers_len; k++) {
        uint32_t v = integers[k];

        // Special case: 0 encodes as one byte 0x00
        if (v == 0) {
            output[out_len++] = 0;
            continue;
        }

        // Collect 7-bit groups, least-significant first
        uint8_t tmp[5];
        size_t n = 0;
        while (v > 0) {
            tmp[n++] = (uint8_t)(v & VLQ_DATA);
            v >>= 7;
        }

        // Emit most-significant group first
        for (size_t i = n; i > 0; i--) {
            uint8_t byte = tmp[i - 1];
            if (i != 1) {                 // not last emitted byte
                byte |= VLQ_CONT;         // set continuation bit
            }
            output[out_len++] = byte;
        }
    }

    return (int)out_len;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
    if (output == NULL) return -1;
    if (buffer_len > 0 && bytes == NULL) return -1;

    size_t out_len = 0;
    uint32_t value = 0;
    int in_progress = 0;   // have we started a number?

    // Count bytes used for current number to enforce <= 5 bytes for uint32_t
    size_t used = 0;

    for (size_t i = 0; i < buffer_len; i++) {
        uint8_t b = bytes[i];
        uint8_t data = b & VLQ_DATA;

        // If we’re starting a new number
        if (!in_progress) {
            value = 0;
            used = 0;
            in_progress = 1;
        }

        // Enforce length limit: 32-bit values should not need > 5 bytes
        used++;
        if (used > 5) {
            return -1;
        }

        // Overflow guard before shifting left 7:
        // if value has any bits set above the top 25 bits, shifting would overflow 32-bit
        if (value > (UINT32_MAX >> 7)) {
            return -1;
        }

        value = (value << 7) | data;

        // If continuation bit is clear, this number ends here
        if ((b & VLQ_CONT) == 0) {
            output[out_len++] = value;
            in_progress = 0;
        }
    }

    // If we ended while still expecting more bytes → error (incomplete sequence)
    if (in_progress) {
        return -1;
    }

    return (int)out_len;
}
