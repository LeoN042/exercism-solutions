#include "rational_numbers.h"
#include <math.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

rational_t reduce(rational_t r) {
    int cd = gcd(r.denominator, r.numerator);
    r.denominator /= cd;
    r.numerator /= cd;

    if (r.denominator < 0) {
        r.denominator = -r.denominator;
        r.numerator = -r.numerator;
    }
    return r;
}

rational_t add(rational_t a, rational_t b) {
    rational_t result;
    result.denominator = a.denominator * b.denominator;
    result.numerator = a.denominator * b.numerator + a.numerator * b.denominator;
    
    return reduce(result);
}

rational_t subtract(rational_t a, rational_t b) {
    rational_t result;
    result.denominator = a.denominator * b.denominator;
    result.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
    
    return reduce(result);
}

rational_t multiply(rational_t a, rational_t b) {
    if (a.numerator == 0) { return a; }
    if (b.numerator == 0) {return b; }
    rational_t result;
    result.denominator = a.denominator * b.denominator;
    result.numerator = a.numerator * b.numerator;
    
    return reduce(result);
}

rational_t divide(rational_t a, rational_t b) {
    rational_t result;
    result.denominator = a.denominator * b.numerator;
    result.numerator = a.numerator * b.denominator;
    
    return reduce(result);
}

rational_t absolute(rational_t r) {
    if (r.denominator < 0) {
        r.denominator = -r.denominator;
    }
    if (r.numerator < 0) {
        r.numerator = -r.numerator;
    }
    return reduce(r);
}

rational_t exp_rational(rational_t r, int n) {
    int denominator = r.denominator;
    int numerator = r.numerator;
    if (n == 0) {
        r.denominator = 1;
        r.numerator = 1;
    }
    else if (n > 0) {
        for (int i = 0; i < n - 1; i++) {
            r.denominator *= denominator;
            r.numerator *= numerator;
        }
    }
    else  {
        r.denominator = numerator;
        r.numerator = denominator;
        for (int i = 0; i < -n - 1; i++) {
            r.denominator *= numerator;
            r.numerator *= denominator;
        }
    }
    return reduce(r);
}

float exp_real(int x, rational_t r) {
    if (r.numerator == 0) {
        return 1.0;
    }
    double exponent = (double)r.numerator / (double)r.denominator;
    return (float)pow((double)x, exponent);
}