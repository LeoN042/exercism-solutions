#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t resistor[]) {
    int value = ((int) resistor[0]) * 10 + ((int) resistor[1]);
    resistor_unit_t unit;
    resistor_value_t comb;
    if (value < 10) {
        switch (resistor[2]) {
            case BLACK:
                unit = OHMS;
                break;
            case BROWN:
                value *= 10;
                unit = OHMS;
                break;
            case RED:
                value *= 100;
                unit = OHMS;
                break;
            case ORANGE:
                unit = KILOOHMS;
                break;
            case YELLOW:
                value *= 10;
                unit = KILOOHMS;
                break;
            case GREEN:
                value *= 100;
                unit = KILOOHMS;
                break;
            case BLUE:
                unit = MEGAOHMS;
                break;
            case VIOLET:
                value *= 10;
                unit = MEGAOHMS;
                break;
            case GREY:
                value *= 100;
                unit = MEGAOHMS;
                break;
            case WHITE:
                unit = GIGAOHMS;
                break;
        }

    }
    else {
        switch (resistor[2]) {
            case BLACK:
                unit = OHMS;
                break;
            case BROWN:
                value *= 10;
                unit = OHMS;
                break;
            case RED:
                value /= 10;
                unit = KILOOHMS;
                break;
            case ORANGE:
                unit = KILOOHMS;
                break;
            case YELLOW:
                value *= 10;
                unit = KILOOHMS;
                break;
            case GREEN:
                value /= 10;
                unit = MEGAOHMS;
                break;
            case BLUE:
                unit = MEGAOHMS;
                break;
            case VIOLET:
                value *= 10;
                unit = MEGAOHMS;
                break;
            case GREY:
                value /= 10;
                unit = GIGAOHMS;
                break;
            case WHITE:
                unit = GIGAOHMS;
                break;
        }
    }
    comb.value = value;
    comb.unit = unit;
    return comb;
}