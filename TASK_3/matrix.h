#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

Matrix matrix_create(int rows, int cols);
void matrix_destroy(Matrix *m);

void matrix_set(Matrix *m, int r, int c, int value);
int matrix_get(const Matrix *m, int r, int c);

int matrix_same_size(const Matrix *a, const Matrix *b);

Matrix matrix_add(const Matrix *a, const Matrix *b);
Matrix matrix_sub(const Matrix *a, const Matrix *b);

void matrix_print(const Matrix *m);

#endif
