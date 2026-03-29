#include "yacht.h"

int score(dice_t dice, category_t category) {
    int sc = 0;
    int str[5] = {0};
    int fir = 0;
    int fir_cnt = 0;
    int sec = 0;
    int sec_cnt = 0;
    int flag = 0;
    switch (category) {
        case ONES:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 1) {
                    sc += 1;
                }
            }
            break;
        case TWOS:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 2) {
                    sc += 2;
                }
            }
            break;
        case THREES:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 3) {
                    sc += 3;
                }
            }
            break;
        case FOURS:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 4) {
                    sc += 4;
                }
            }
            break;
        case FIVES:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 5) {
                    sc += 5;
                }
            }
            break;
        case SIXES:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 6) {
                    sc += 6;
                }
            }
            break;
        case FULL_HOUSE:
            fir = dice.faces[0];
            fir_cnt = 1;
            for (int i = 1; i < 5; i++) {
                if (dice.faces[i] != fir) {
                    if (sec == 0) {
                        sec = dice.faces[i];
                        sec_cnt = 1;
                    }
                    else if (dice.faces[i] == sec) {
                        sec_cnt++;
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
                else {
                    fir_cnt++;
                }
            }
            if (flag == 0 && (fir_cnt == 2 || fir_cnt == 3)) {
                sc = fir * fir_cnt + sec * sec_cnt;
            }
            else {
                sc = 0;
            }
            break;
        case FOUR_OF_A_KIND:
            fir = dice.faces[0];
            fir_cnt = 1;
            for (int i = 1; i < 5; i++) {
                if (dice.faces[i] != fir) {
                    if (sec == 0) {
                        sec = dice.faces[i];
                        sec_cnt = 1;
                    }
                    else if (dice.faces[i] == sec) {
                        sec_cnt++;
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
                else {
                    fir_cnt++;
                }
            }
            if (sec == 0) {
                sc = fir * 4;
                break;
            }
            if (flag == 0) {
                if (fir_cnt == 1) {
                    sc = sec * sec_cnt;
                }
                else if (sec_cnt == 1) {
                    sc = fir * fir_cnt;
                }
                else {
                    sc = 0;
                }
            }
            else {
                sc = 0;
            }
            break;
        case LITTLE_STRAIGHT:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 6) {
                    flag = 1;
                    break;
                }
                str[dice.faces[i] - 1] += 1;
            }
            for (int i = 0; i < 5; i++) {
                if (str[i] != 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                sc = 30;
            }
            else {
                sc = 0;
            }
            break;
        case BIG_STRAIGHT:
            for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == 1) {
                    flag = 1;
                    break;
                }
                str[dice.faces[i] - 2] += 1;
            }
            for (int i = 0; i < 5; i++) {
                if (str[i] != 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                sc = 30;
            }
            else {
                sc = 0;
            }
            break;
        case CHOICE:
            for (int i = 0; i < 5; i++) {
                sc += dice.faces[i];
            }
            break;
        case YACHT: {
            int val = dice.faces[0];
            for (int i = 1; i < 5; i++) {
                if (dice.faces[i] != val) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                sc = 50;
            }
            else {
                sc = 0;
            }
            break;
        }
        default:
            sc = 0;
            break;
    }
    return sc;
}