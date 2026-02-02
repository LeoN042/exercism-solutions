#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>

static char *empty_string(void) {
    char *s = malloc(1);
    if (s) s[0] = '\0';
    return s;
}

char *count(const char *dna_strand) {
    if (dna_strand == NULL) { return NULL; }
    char *output = malloc(50);
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;
    for (int i = 0; dna_strand[i] != '\0'; i++) {
        switch (dna_strand[i]) {
            case 'A':
                a++;
                break;
            case 'C':
                c++;
                break;
            case 'G':
                g++;
                break;
            case 'T':
                t++;
                break;
            default:
                return empty_string();
        }
    }
    snprintf(output, 50, "A:%d C:%d G:%d T:%d", a, c, g, t);
    return output;
}