#include "beer_song.h"
#include <stdio.h>
#include <stdint.h>

static const char *bottle_word(int n) {
    return (n == 1) ? "bottle" : "bottles";
}

static void write_verse_lines(int n, char **song, uint16_t *line) {
    if (n > 0) {
        // Line 1
        snprintf(song[*line], 1024,
                 "%d %s of beer on the wall, %d %s of beer.",
                 n, bottle_word(n), n, bottle_word(n));
        (*line)++;

        // Line 2
        if (n == 1) {
            // next is 0
            snprintf(song[*line], 1024,
                     "Take it down and pass it around, no more bottles of beer on the wall.");
        } else {
            // next is n-1
            int next = n - 1;
            snprintf(song[*line], 1024,
                     "Take one down and pass it around, %d %s of beer on the wall.",
                     next, bottle_word(next));
        }
        (*line)++;
    } else {
        // n == 0 special verse
        snprintf(song[*line], 1024,
                 "No more bottles of beer on the wall, no more bottles of beer.");
        (*line)++;

        snprintf(song[*line], 1024,
                 "Go to the store and buy some more, 99 bottles of beer on the wall.");
        (*line)++;
    }
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    uint16_t line = 0;

    for (uint8_t v = 0; v < take_down; v++) {
        int n = (int)start_bottles - (int)v;

        // (Not needed for current tests, but avoids going negative.)
        if (n < 0) break;

        write_verse_lines(n, song, &line);

        // blank line between verses, not after the last one
        if (v + 1 < take_down) {
            song[line][0] = '\0';
            line++;
        }
    }
}
