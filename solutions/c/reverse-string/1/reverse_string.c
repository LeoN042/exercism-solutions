#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
    int len = strlen(value);
    char *output = malloc(len + 1);
    for (int i = 0; i < (len + 1) / 2; i++) {
        output[i] = value[len - 1 - i];
        output[len - 1 - i] = value[i];
    }
    output[len] = '\0';
    return output;
}