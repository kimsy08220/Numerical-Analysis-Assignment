#include <stdio.h>

double ABS(double x) {
	return x < 0 ? -x : x;
}

double f(double x) {
	return -0.9 * x * x + 1.7 * x + 2.5;
}

double f_1(double x) {
	return -1.8 * x + 1.7;
}

void Newton_Raphson(double xr, double ea)
{
	int iter = 0;
	double xrold;

	printf("	   [Newton_Raphson result]\n");
	printf("--------------------------------------------\n");
	printf("Iteration	   xi	     	   ea\n");
	printf("--------------------------------------------\n");


	while (1)
	{
		xrold = xr;
		xr = xrold - (f(xrold) / f_1(xrold));
		iter = iter + 1;

		if (xr != 0)
			ea = ABS((xr - xrold) / xr) * 100;

		printf("    %d		%lf	", iter, xr);

		if (iter != 1)
			printf("%9lf\n", ea);
		else
			printf("\n");

		if (ea < 0.01)
		{
			printf("--------------------------------------------\n\n");
			printf("±Ù(x) : %lf\n\n", xr);
			break;
		}
	}
}

int main(void)
{
	double x0 = 5, ea = 0;
	Newton_Raphson(x0, ea);
	return  0;
}