#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LU_factorization(double** a, double** l, double** u, int n)
{
	int i = 0, j = 0, k = 0;

	for (i = 0; i < n; i++)
	{

		for (j = 0; j < n; j++)
		{
			if (j < i)
				u[i][j] = 0;
			else
			{
				u[i][j] = a[i][j];

				for (k = 0; k < i; k++)
				{
					u[i][j] = u[i][j] - (l[i][k] * u[k][j]);
				}
			}

			if (j < i)
				l[j][i] = 0;
			else
			{
	
				if (u[i][i]==0)
				{
					error(1, "Rozklad LU podanej macierzy niemozliwy korzystajac z metody Choleskiego.");
				}

				l[j][i] = a[j][i] / u[i][i];

				for (k = 0; k < i; k++)
				{
					l[j][i] = l[j][i] - ((l[j][k] * u[k][i]) / u[i][i]);
				}
			}

		}

	}

}

void solving_equation(double** l, double** u, double* b, double* x, double* y, int n)
{

	for (int i = 0; i < n; i++)
	{
		y[i] = b[i] / l[i][i];
		for (int k = 0; k < i; k++)
		{
			y[i] = y[i] - ((l[i][k] * y[k])/l[i][i]);
		}
	}

	for (int i = n-1; i>=0 ; i--)
	{
		x[i] = y[i] / u[i][i];

		for (int k = n-1; k > i ; k--)
		{
			x[i] = x[i] - ((u[i][k] *x[k]) / u[i][i]);
		}

	}

}

