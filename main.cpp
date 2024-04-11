#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#pragma warning(disable:4996)


int main(int argc,char** argv)
{
	FILE* fd, * fw;
	int n;
	double** a, ** l, ** u;
	double* b,*x,*y;

	argumenty(argc, argv);

	if (!(fd = fopen(argv[1], "r"))) 
		error(2, "dane");
	if (!(fw = fopen(argv[2], "w"))) 
		error(2, "wyniki");

	if(!(fscanf(fd,"%d", &n)) || n > 20 || n < 1) 
		error(1, "Niepoprawny rozmiar macierzy ( 0 < n <=20 )!");


	a = matrix_allocation(n);
	l = matrix_allocation(n);
	u = matrix_allocation(n);

	b = vector_allocation(n);
	y = vector_allocation(n);
	x = vector_allocation(n);

	read_matrix(fd,a, n);

	read_vector(fd, b, n);

	
	LU_factorization(a,l,u,n);

	solving_equation(l, u, b, x, y,n);

	print_LU_and_X(l, u, x, n, fw);

	free_matrix(a,n);
	free_matrix(l,n);
	free_matrix(u,n);

	free_vector(b,n);
	free_vector(y,n);
	free_vector(x,n);

}



