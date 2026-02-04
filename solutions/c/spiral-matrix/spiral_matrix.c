#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int input) {
    if (input < 0) {
        return NULL;
    }
    spiral_matrix_t *matrix_type = malloc(sizeof(*matrix_type));
    matrix_type->size = input;

    if (input == 0) {
        matrix_type->matrix = NULL;
        return matrix_type;
    }

    matrix_type->matrix = malloc((size_t)input * sizeof(*matrix_type->matrix));
    for (int i = 0; i < input; i++) {
        matrix_type->matrix[i] = malloc((size_t)input * sizeof(*matrix_type->matrix[i]));
    }

    int top = 0; int bot = input - 1; 
    int left = 0; int right = input - 1;
    int val = 1;
    while (left <= right) {
        for (int j = left; j <= right; j++) matrix_type->matrix[top][j] = val++;
        top++;

        for (int i = top; i <= bot; i++) matrix_type->matrix[i][right] = val++;
        right--;

        for (int j = right; j >= left; j--) matrix_type->matrix[bot][j] = val++;
        bot--;

        for (int i = bot; i >= top; i--) matrix_type->matrix[i][left] = val++;
        left++;
        
    }
    return matrix_type;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix_type) {
    for (int i = 0; i < matrix_type->size; i++) {
        free(matrix_type->matrix[i]);
    }
    free(matrix_type->matrix);
    free(matrix_type);
}