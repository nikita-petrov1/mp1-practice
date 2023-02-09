#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() {
	Matrix* m1, *m2, *res;
	alloc_matrix(&m1, 2);
	alloc_matrix(&m2, 2);
	fill_matrix(m1);
	fill_matrix(m1);

	res = addition_matrix(m1, m2);
	print_matrix(res);
	return 0;
}