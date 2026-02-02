#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>

int ability(void) {
    int dices[4];
    for (int i = 0; i < 4; i++) {
        dices[i] = rand() % 6 + 1;
    }
    int min = 7;
    int sum = 0;
    for (int j = 0; j < 4; j++) {
        if (min > dices[j]) {
            min = dices[j];
        }
        sum += dices[j];
    }
    sum -= min;
    return sum;
}
int modifier(int score){
    return score / 2 - 5;
}
dnd_character_t make_dnd_character(void){
    dnd_character_t ch;
    ch.strength = ability();
    ch.dexterity = ability();
    ch.constitution = ability();
    ch.intelligence = ability();
    ch.wisdom = ability();
    ch.charisma = ability();
    ch.hitpoints = 10 + modifier(ch.constitution);
    return ch;
}