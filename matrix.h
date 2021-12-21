#include <stdio.h>

typedef struct Matrix {
    unsigned m, n;
    long double **elem;
} matrix;

long double abs_d (long double x);

matrix *new_matrix (unsigned m, unsigned n);
matrix *copy_matrix (matrix *matr);
void delete_matrix (matrix *matr);
void print_matrix (matrix *matr);
void print_matrix_ext (matrix *A, matrix *f);
void read_matrix (FILE *input, matrix *matr);

unsigned leading_element (matrix *matr, unsigned n_st, unsigned m_aim);
void triangulate_matrix (matrix *matr, matrix *f, int *reverse);
unsigned *triangulate_matrix_lead (matrix *matr, matrix *f);

long double determinant (matrix *matr);
long double *gauss_method (matrix *A1, matrix *f1, int lead);
