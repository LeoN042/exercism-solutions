#include "protein_translation.h"

protein_t protein(const char *const rna) {
    protein_t protein = {.valid=true, .count=0, .amino_acids={0}};
    for (int i = 0; rna[i] != '\0'; i+=3) {
        char fir = rna[i];
        char sec = rna[i+1];
        if (sec == '\0') {
            protein.valid = false;
            return protein;
        }
        char thi = rna[i+2];
        if (thi == '\0') {
            protein.valid = false;
            return protein;
        }
        switch (fir) {
            case 'A':
                if (sec == 'U' && thi == 'G') {
                    protein.valid = true;
                    protein.amino_acids[protein.count] = Methionine;
                    protein.count++;
                }
                else {
                    protein.valid = false;
                    return protein;
                }
                break;
            case 'U':
                if (sec == 'U') {
                    if (thi == 'U' || thi == 'C') {
                        protein.valid = true;
                        protein.amino_acids[protein.count] = Phenylalanine;
                        protein.count++;
                    }
                    else if (thi == 'A' || thi == 'G') {
                        protein.valid = true;
                        protein.amino_acids[protein.count] = Leucine;
                        protein.count++;
                    }
                    else {
                        protein.valid = false;
                        return protein;
                    }
                }
                else if (sec == 'C') {
                    if (thi == 'U' || thi == 'C' || thi == 'A' || thi == 'G') {
                        protein.valid = true;
                        protein.amino_acids[protein.count] = Serine;
                        protein.count++;
                    }
                    else {
                        protein.valid = false;
                        return protein;
                    }
                }
                else if (sec == 'A') {
                    if (thi == 'U' || thi == 'C') {
                        protein.valid = true;
                        protein.amino_acids[protein.count] = Tyrosine;
                        protein.count++;
                    }
                    else if (thi == 'A' || thi == 'G') {
                        protein.valid = true;
                        return protein;
                    }
                    else {
                        protein.valid = false;
                        return protein;
                    }
                }
                else if (sec == 'G') {
                    if (thi == 'U' || thi == 'C') {
                        protein.valid = true;
                        protein.amino_acids[protein.count] = Cysteine;
                        protein.count++;
                    }
                    else if (thi == 'G') {
                        protein.valid = true;
                        protein.amino_acids[protein.count] = Tryptophan;
                        protein.count++;
                    }
                    else if (thi == 'A') {
                        protein.valid = true;
                        return protein;
                    }
                    else {
                        protein.valid = false;
                        return protein;
                    }
                }
                else {
                    protein.valid = false;
                    return protein;
                }
                break;
            default:
                protein.valid = false;
                return protein;
        }
        
    }
    return protein;
}