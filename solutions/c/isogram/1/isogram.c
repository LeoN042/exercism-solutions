#include "isogram.h"
#include <string.h>
bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }
    int i = 0;
    int alphabet[26] = {0};
    while (phrase[i] != '\0') {
        int character = (phrase[i] | 0x20) - 'a';
        if (character >= 0 && character < 26) {
            alphabet[character] += 1;
        }
        i++;
    }
    for (int j = 0; j < 26; j++) {
        if (alphabet[j] > 1) {
            return false;
        }
    }
    return true;
}