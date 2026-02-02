#include "clock.h"

clock_t clock_create(int hour, int minute) {
    clock_t clock;
    int total = (hour * 60 + minute) % (24 * 60);
    if (total < 0) { total += 24 * 60; }
    int m = total % 60;
    int h = total / 60;
    snprintf(clock.text, sizeof(clock.text), "%02d:%02d", h, m); 
    return clock;
}
clock_t clock_add(clock_t clock, int minute_add) {
    int hour = (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
    int minute = (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
    int total = (hour * 60 + minute + minute_add) % (24 * 60);
    if (total < 0) { total += 24 * 60; }
    int m = total % 60;
    int h = total / 60;
    snprintf(clock.text, sizeof(clock.text), "%02d:%02d", h, m); 
    return clock;
}
clock_t clock_subtract(clock_t clock, int minute_subtract) {
    int hour = (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
    int minute = (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
    int total = (hour * 60 + minute - minute_subtract) % (24 * 60);
    if (total < 0) { total += 24 * 60; }
    int m = total % 60;
    int h = total / 60;
    snprintf(clock.text, sizeof(clock.text), "%02d:%02d", h, m); 
    return clock;
}
bool clock_is_equal(clock_t a, clock_t b) {
    int ahour = (a.text[0] - '0') * 10 + (a.text[1] - '0');
    int aminute = (a.text[3] - '0') * 10 + (a.text[4] - '0');
    int bhour = (b.text[0] - '0') * 10 + (b.text[1] - '0');
    int bminute = (b.text[3] - '0') * 10 + (b.text[4] - '0');
    return (ahour == bhour) && (aminute == bminute);
}