#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void argumenty(int argc, char** argv)
{
	int len;
	char* usage;
	if (argc != 3)
	{
		len = strlen(argv[0]) + 19;
		if (!(usage = (char*)malloc((unsigned)len * sizeof(char))))
			error(3, "tablica usage");
		strcpy(usage, argv[0]);
		strcat(usage, " file_in file_out");
		error(4, usage);
	}
}

double** matrix_allocation(int n)
{
	double** ma = (double**)malloc(sizeof(double*) * n);
	
	if (!ma)
		error(3, "Blad alokacji pamieci dla macierzy");
	
		for (int i = 0; i < n; i++)
		{
			ma[i] = (double*)malloc(sizeof(double) * n);

			if (!ma[i])
				error(3, "Blad alokacji pamieci dla macierzy");
		}

	return ma;

}

double* vector_allocation(int n)
{
	double* v = (double*)malloc(sizeof(double) * n);
	if (!v)
		error(3, "Blad alokacji pamieci dla wektora");

	return v;
}

void read_matrix(FILE* fd, double** ma, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (fscanf(fd, "%lf", &ma[i][j]) != 1)
				error(1, "Niepoprawny zapis macierzy!");

			if(ma[i][j]>1000000)
				error(1, "Wystepuje zbyt duza liczba w macierzy!");
			
		}

}

void read_vector(FILE* fd, double* v, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (fscanf(fd, "%lf", &v[i]) != 1)
			error(1, "Niepoprawny zapis wektora!");

		if (v[i] > 1000000)
			error(1, "Wystepuje zbyt duza liczba w wektorze!");
	}

}

void print_LU_and_X(double** l, double** u, double* x, int n, FILE* f)
{
	printf("Macierz gorno trojkatna: \n\n");
	fprintf(f, "Macierz gorno trojkatna: \n\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.3lf  ", u[i][j]);
			fprintf(f, "%.3lf  ", u[i][j]);
		}
		printf("\n\n");
		fprintf(f, "\n\n");
	}

	printf("\n\nMacierz dolno trojkatna: \n\n");
	fprintf(f, "\n\nMacierz dolno trojkatna: \n\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.3lf  ", l[i][j]);
			fprintf(f, "%.3lf  ", l[i][j]);
		}
		printf("\n\n");
		fprintf(f, "\n\n");
	}

	printf("\n\nRozwiazania ukladu: \n\n");
	fprintf(f, "\n\nRozwiazania ukladu: \n\n");

	for (int i = 0; i < n; i++)
	{
		printf("x%d = %.10lf\n\n", i + 1, x[i]);
		fprintf(f, "x%d = %.10lf\n\n", i + 1, x[i]);
	}
}

void free_matrix(double** ma, int n)
{
	for (int i = 0; i < n; i++)
		free(ma[i]);
		
	free(ma);

	ma = NULL;

}

void free_vector(double* v, int n)
{
	free(v);
	v = NULL;
}

