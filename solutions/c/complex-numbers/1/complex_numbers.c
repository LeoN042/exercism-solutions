#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
   // TODO: implement
    complex_t complex;
    complex.real = a.real + b.real;
    complex.imag = a.imag + b.imag;
    return complex;
}

complex_t c_sub(complex_t a, complex_t b)
{
   // TODO: implement
    complex_t complex;
    complex.real = a.real - b.real;
    complex.imag = a.imag - b.imag;
    return complex;
}

complex_t c_mul(complex_t a, complex_t b)
{
   // TODO: implement
    complex_t complex;
    complex.real = a.real * b.real - a.imag * b.imag;
    complex.imag = a.real * b.imag + a.imag * b.real;
    return complex;
}

complex_t c_div(complex_t a, complex_t b)
{
   // TODO: implement
    complex_t complex;
    complex.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    complex.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
    return complex;
}

double c_abs(complex_t x)
{
   // TODO: implement
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
   // TODO: implement
    x.imag = -x.imag;
    return x;
}

double c_real(complex_t x)
{
    // TODO: implement
    return x.real;
}

double c_imag(complex_t x)
{
   // TODO: implement
    return x.imag;
}

complex_t c_exp(complex_t x)
{
   // TODO: implement
    complex_t complex;

    double exp_real = exp(x.real);   // e^a
    complex.real = exp_real * cos(x.imag);
    complex.imag = exp_real * sin(x.imag);

    return complex;
}
