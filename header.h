#include <stdlib.h>
#include <stdio.h>

void error(int, const char*);
void argumenty(int, char**);

double** matrix_allocation(int);
void read_matrix(FILE* ,double**, int);

double* vector_allocation(int n);
void read_vector(FILE*, double*, int);

void LU_factorization(double**, double**, double**, int);
void solving_equation(double**, double**, double*, double*, double*, int);

void print_LU_and_X(double**, double**,double*, int, FILE*);

void free_matrix(double**, int);
void free_vector(double*, int);
