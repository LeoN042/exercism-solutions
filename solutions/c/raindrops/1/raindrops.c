#include "raindrops.h"
// #include <string.h>
#include <stdio.h>

void convert(char result[], int drops) {
    char *pling = NULL;
    char *plang = NULL;
    char *plong = NULL;
    if (drops % 3 == 0) {
        pling = "Pling";
    }
    if (drops % 5 == 0) {
        plang = "Plang";
    }
    if (drops % 7 == 0) {
        plong = "Plong";
    }
    if (pling == NULL && plang == NULL && plong == NULL) {
        sprintf(result, "%d", drops);
    }
    else {
        sprintf(result, "%s%s%s", pling? pling : "", plang? plang : "", plong? plong : "");
    }
}