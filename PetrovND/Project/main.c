#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() {
	Matrix* m1, *m2, *res;

	alloc_matrix(&m1, 2);
	alloc_matrix(&m2, 2);

	fill_matrix(m1);
	fill_matrix(m2);

	res = addition_matrix(m1, m2);
	print_matrix(res);

	res = addition_constant(m1, 3.7);
	print_matrix(res);

	res = matrix_multiplication(m1, m2);
	print_matrix(res);

	res = multiplication_by_constant(m2, 1.5);
	print_matrix(res);

	free_matrix(&m1);
	free_matrix(&m2);
	free_matrix(&res);
	return 0;
}