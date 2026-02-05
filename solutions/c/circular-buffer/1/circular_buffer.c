#include "circular_buffer.h"

#include <stdlib.h>
#include <errno.h>

struct circular_buffer {
    size_t capacity;
    size_t head;   // next position to read
    size_t tail;   // next position to write
    size_t count;  // number of items currently stored
    buffer_value_t *data;
};

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    circular_buffer_t *buf = malloc(sizeof(*buf));
    if (!buf) {
        return NULL;
    }

    buf->capacity = capacity;
    buf->head = 0;
    buf->tail = 0;
    buf->count = 0;

    buf->data = NULL;
    if (capacity > 0) {
        buf->data = malloc(capacity * sizeof(*buf->data));
        if (!buf->data) {
            free(buf);
            return NULL;
        }
    }

    return buf;
}

void delete_buffer(circular_buffer_t *buffer)
{
    if (!buffer) return;
    free(buffer->data);
    free(buffer);
}

void clear_buffer(circular_buffer_t *buffer)
{
    if (!buffer) return;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    // no need to wipe data; count controls validity
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (!buffer || buffer->capacity == 0) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    if (buffer->count == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->data[buffer->tail] = value;
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->count++;

    errno = 0;
    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value)
{
    if (!buffer || !value) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    if (buffer->count == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *value = buffer->data[buffer->head];
    buffer->head = (buffer->head + 1) % buffer->capacity;
    buffer->count--;

    errno = 0;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    if (!buffer || buffer->capacity == 0) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    // If full, drop the oldest element by advancing head
    if (buffer->count == buffer->capacity) {
        buffer->head = (buffer->head + 1) % buffer->capacity;
        buffer->count--; // make room
    }

    // Now behave like write
    buffer->data[buffer->tail] = value;
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->count++;

    errno = 0;
    return EXIT_SUCCESS;
}
