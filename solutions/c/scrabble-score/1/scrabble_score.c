#include "scrabble_score.h"

unsigned int score(const char *word) {
    unsigned int sc = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = word[i] & (~0x20);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
            ch == 'U' || ch == 'L' || ch == 'N' || ch == 'R' ||
            ch == 'S' || ch == 'T') {
                sc += 1;
            }
        else if (ch == 'D' || ch == 'G') {
            sc += 2;
        }
        else if (ch == 'B' || ch == 'C' || ch == 'M' || ch == 'P') {
            sc += 3;
        }
        else if (ch == 'F' || ch == 'H' || ch == 'V' ||
                 ch == 'W' || ch == 'Y') {
            sc += 4;
        }
        else if (ch == 'K') {
            sc += 5;
        }
        else if (ch == 'J' || ch == 'X') {
            sc += 8;
        }
        else if (ch == 'Q' || ch == 'Z') {
            sc += 10;
        }
        else {
            return 0;
        }
    }
    return sc;
}