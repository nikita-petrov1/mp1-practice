#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void alloc_matrix(Matrix** matrix, int n) {
	*matrix = (Matrix*)malloc(sizeof(Matrix) * 1);
	(*matrix)->n = n;
	(*matrix)->data = (double*)malloc(n*n * sizeof(double));
}

void free_matrix(Matrix** matrix) {
	free((*matrix)->data);
	free(*matrix);
}

void fill_matrix(Matrix* matrix) {
	int i = 0;
	for (; i < matrix->n; i++) {
		int j = 0;
		for (; j < matrix->n; j++) {
			scanf("%lf", &(matrix->data[i * matrix->n + j]));
		}
	}
	printf("\n");
}

void print_matrix(Matrix* matrix) {
	int i = 0;
	for (; i < matrix->n; i++) {
		int j = 0;
		for (; j < matrix->n; j++) {
			printf("%.2lf ", matrix->data[i * matrix->n + j]);
		}
		printf(" \n");
	}
	printf("\n");
}

Matrix* addition_matrix(Matrix* m1, Matrix* m2) {
	int i = 0;
	int n;
	Matrix* result;
	if (m1->n != m2->n) {
		printf("ERROR: Matrices must have equal dimensions!");
		return NULL;
	}
	n = m1->n;
	alloc_matrix(&result, n);
	for (; i < n*n; i++) {
		result->data[i] = m1->data[i] + m2->data[i];
	}
	return result;
}

Matrix* addition_constant(Matrix* matrix, double constant){
	int i = 0;
	Matrix* result;
	int n = matrix->n;
	alloc_matrix(&result, n);
	for (; i < n * n; i++) {
		result->data[i] = matrix->data[i] + constant;
	}
	return result;
}

Matrix* multiplication_by_constant(Matrix* matrix, double constant) {
	int i = 0;
	Matrix* result;
	int n = matrix->n;
	alloc_matrix(&result, n);
	for (; i < n * n; i++) {
		result->data[i] = matrix->data[i] * constant;
	}
	return result;
}

Matrix* matrix_multiplication(Matrix* m1, Matrix* m2) {
	Matrix* result;
	int i, j, k, n;
	if (m1->n != m2->n) {
		printf("ERROR: Matrices must have equal dimensions!");
		return NULL;
	}
	n = m1->n;
	alloc_matrix(&result, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result->data[i * n + j] = 0;
			for (k = 0; k < n; k++) {
				result->data[i * n + j] += m1->data[i * n + k] * m2->data[k * n + j];
			}
		}
	}
	return result;
}