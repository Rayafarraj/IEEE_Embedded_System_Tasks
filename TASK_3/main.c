#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix A = matrix_create(2, 2);
    Matrix B = matrix_create(2, 2);

    int val = 1;
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            matrix_set(&A, i, j, val++);
        }
    }

    val = 5;
    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            matrix_set(&B, i, j, val++);
        }
    }

    if (!matrix_same_size(&A, &B)) {
        printf("Size mismatch\n");
        return 1;
    }

    Matrix sum = matrix_add(&A, &B);
    Matrix diff = matrix_sub(&A, &B);

    printf("Sum:\n");
    matrix_print(&sum);

    printf("\nDiff:\n");
    matrix_print(&diff);

    matrix_destroy(&A);
    matrix_destroy(&B);
    matrix_destroy(&sum);
    matrix_destroy(&diff);

    return 0;
}
