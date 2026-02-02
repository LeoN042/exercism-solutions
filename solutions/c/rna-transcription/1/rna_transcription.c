#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna) {
    if (dna == NULL) {
        return NULL;
    }
    int len = strlen(dna);
    char *rna = malloc(len + 1);
    if (rna == NULL) {
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        if (dna[i] == 'G') {
            rna[i] = 'C';
        }
        else if (dna[i] == 'C') {
            rna[i] = 'G';
        }
        else if (dna[i] == 'T') {
            rna[i] = 'A';
        }
        else if (dna[i] == 'A') {
            rna[i] = 'U';
        }
        else if (dna[i] == '\0') {
            rna[i] = '\0';
        }
    }
    return rna;
}