#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
	int n;
	double* data;
} Matrix;

void alloc_matrix(Matrix** matrix, int n);
void free_matrix(Matrix** matrix);
void fill_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
Matrix* addition_matrix(Matrix* m1, Matrix* m2);
Matrix* addition_constant(Matrix* matrix, double constant);

#endif 
