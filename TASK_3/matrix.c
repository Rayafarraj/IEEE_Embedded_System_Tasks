#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix matrix_create(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int*)malloc(rows * cols * sizeof(int));
    return m;
}

void matrix_destroy(Matrix *m) {
    if (m->data) {
        free(m->data);
        m->data = NULL;
    }
}

void matrix_set(Matrix *m, int r, int c, int value) {
    m->data[r * m->cols + c] = value;
}

int matrix_get(const Matrix *m, int r, int c) {
    return m->data[r * m->cols + c];
}

int matrix_same_size(const Matrix *a, const Matrix *b) {
    return (a->rows == b->rows) && (a->cols == b->cols);
}

Matrix matrix_add(const Matrix *a, const Matrix *b) {
    Matrix res = matrix_create(a->rows, a->cols);

    for (int i = 0; i < a->rows * a->cols; i++) {
        res.data[i] = a->data[i] + b->data[i];
    }

    return res;
}

Matrix matrix_sub(const Matrix *a, const Matrix *b) {
    Matrix res = matrix_create(a->rows, a->cols);

    for (int i = 0; i < a->rows * a->cols; i++) {
        res.data[i] = a->data[i] - b->data[i];
    }

    return res;
}

void matrix_print(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}
