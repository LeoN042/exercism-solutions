#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL) {
        return false;
    }
    int alphabet[26] = {0};
    int len = (int) strlen(sentence);
    for (int i = 0; i < len; i++) {
        if (sentence[i] - 'A' < 26 && sentence[i] - 'A' >= 0) {
            alphabet[sentence[i] - 'A'] += 1;
        }
        else if (sentence[i] - 'a' < 26 && sentence[i] - 'a' >= 0) {
            alphabet[sentence[i] - 'a'] += 1;
        }
    }
    for (int j = 0; j < 26; j++) {
        if (alphabet[j] == 0) {
            return false;
        }
    }
    return true;
}