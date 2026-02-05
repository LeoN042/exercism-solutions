#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>   // EXIT_SUCCESS / EXIT_FAILURE

// The tests treat values as integers and print with %d.
// int16_t is a common choice in this Exercism exercise.
typedef int16_t buffer_value_t;

// Opaque type: defined in circular_buffer.c
typedef struct circular_buffer circular_buffer_t;

// Create / destroy
circular_buffer_t *new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *buffer);

// Operations
int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t read(circular_buffer_t *buffer, buffer_value_t *value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
void clear_buffer(circular_buffer_t *buffer);

#endif
