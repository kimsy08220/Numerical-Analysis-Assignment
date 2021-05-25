#include <stdio.h>
#define NUM 3

double ABS(double x) {
	return x < 0 ? -x : x;
}

void print(double a[NUM][NUM], int n, double b[NUM])
{
	printf("\t   x1\t\t   x2\t\t    x3\t\t   b\n");
	printf("\t----------------------------------------------------------\n");
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
			printf("\t%9lf", a[i][j]);
		printf("\t%9lf\n", b[i]);
	}
	printf("\n");
}

void Pivot(double a[NUM][NUM], double b[NUM], double s[NUM], int n, int k)
{
	int p = k;
	double big = 0, dummy = 0;

	big = ABS(a[k][k] / s[k]);
	for (int ii = k + 1; ii < n; ii++)
	{
		dummy = ABS(a[ii][k] / s[ii]);
		if (dummy > big)
		{
			big = dummy;
			p = ii;
		}
	}
	if (p != k)
	{
		for (int jj = k; jj < n; jj++)
		{
			dummy = a[p][jj];
			a[p][jj] = a[k][jj];
			a[k][jj] = dummy;
		}
		dummy = b[p];
		b[p] = b[k];
		b[k] = dummy;

		dummy = s[p];
		s[p] = s[k];
		s[k] = dummy;
	}

	printf("\n\t<Pivoting x%d>\n", k + 1);
	print(a, n, b);
}

void Eliminate(double a[NUM][NUM], double s[NUM], int n, double b[NUM], double tol, int er)
{
	double factor = 0;

	for (int k = 0; k < n - 1; k++)
	{
		Pivot(a, b, s, n, k);
		if (ABS(a[k][k] / s[k]) < tol)
			er = -1;
		for (int i = k + 1; i < n; i++)
		{
			factor = a[i][k] / a[k][k];
			for (int j = k; j < n; j++)
			{
				a[i][j] = a[i][j] - factor * a[k][j];
				if (a[i][j] == 0)
					a[i][j] = 0;
			}
			b[i] = b[i] - factor * b[k];
		}

		printf("\n\t<Eliminate x%d>\n", k + 1);
		print(a, n, b);
	}
	if (ABS(a[n - 1][n - 1] / s[n - 1]) < tol)
		er = -1;
}

void Substitute(double a[NUM][NUM], int n, double b[NUM], double x[NUM])
{
	double sum = 0;
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	printf("\n\t<Substitute>\n\n");

	for (int i = n - 1; i > -1; i--)
	{
		sum = 0;
		for (int j = i + 1; j < n; j++)
			sum = sum + a[i][j] * x[j];
		x[i] = (b[i] - sum) / a[i][i];

		printf("\tx[%d] = %lf\n", i + 1, x[i]);
	}
	printf("\n\n");
}

void Gauss(double a[NUM][NUM], double b[NUM], int n, double x[NUM], double tol, int er)
{
	double s[NUM] = { 0 };

	for (int i = 0; i < n; i++)
	{
		s[i] = ABS(a[i][1]);
		for (int j = 1; j < n; j++)
			if (ABS(a[i][j]) > s[i])
				s[i] = ABS(a[i][j]);
	}
	Eliminate(a, s, n, b, tol, er);
	if (er != -1)
		Substitute(a, n, b, x);
}

int main(void)
{
	int er = 0;
	double a[NUM][NUM] = { {1, 2, -1}, {5, 2, 2}, {-3, 5, -1} };
	double b[NUM] = { 2, 9, 1 };
	double x[NUM] = { 0 };
	double tol = 0;

	printf("\n\t<원래의 연립방정식>\n");
	print(a, NUM, b);

	Gauss(a, b, NUM, x, tol, er);
	return 0;
}