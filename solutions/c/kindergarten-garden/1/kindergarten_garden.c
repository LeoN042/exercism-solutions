#include "kindergarten_garden.h"
#include <string.h>

plants_t plants(const char *diagram, const char *student) {
    plants_t pl = {.plants = {CLOVER}};
    int len = strlen(diagram);
    if (student[0] == 'A') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+0];
            char sec = diagram[i+(len/2+1)+0];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'B') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+2];
            char sec = diagram[i+(len/2+1)+2];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'C') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+4];
            char sec = diagram[i+(len/2+1)+4];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'D') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+6];
            char sec = diagram[i+(len/2+1)+6];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'E') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+8];
            char sec = diagram[i+(len/2+1)+8];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'F') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+10];
            char sec = diagram[i+(len/2+1)+10];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'G') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+12];
            char sec = diagram[i+(len/2+1)+12];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'H') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+14];
            char sec = diagram[i+(len/2+1)+14];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'I') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+16];
            char sec = diagram[i+(len/2+1)+16];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'J') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+18];
            char sec = diagram[i+(len/2+1)+18];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'K') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+20];
            char sec = diagram[i+(len/2+1)+20];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }

    else if (student[0] == 'L') {
        for (int i = 0; i < 2; i++) {
            char fir = diagram[i+22];
            char sec = diagram[i+(len/2+1)+22];
            if (fir == 'C') {
                pl.plants[i] = CLOVER;
            }
            else if (fir == 'G') {
                pl.plants[i] = GRASS;
            }
            else if (fir == 'R') {
                pl.plants[i] = RADISHES;
            }
            else if (fir == 'V') {
                pl.plants[i] = VIOLETS;
            }

            if (sec == 'C') {
                pl.plants[i+2] = CLOVER;
            }
            else if (sec == 'G') {
                pl.plants[i+2] = GRASS;
            }
            else if (sec == 'R') {
                pl.plants[i+2] = RADISHES;
            }
            else if (sec == 'V') {
                pl.plants[i+2] = VIOLETS;
            }

        }
    }
    return pl;
}