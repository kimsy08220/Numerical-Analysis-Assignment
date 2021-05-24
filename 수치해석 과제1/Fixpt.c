#include <stdio.h>

double ABS(double x) {
	return x < 0 ? -x : x;
}

double g(double x) {
	return (1.7 * x + 2.5) / (0.9 * x);
}

void Fixpt(double xr, double ea)
{
	int iter = 0;
	double xrold;

	printf("		[Fixpt result]\n");
	printf("----------------------------------------------\n");
	printf("Iteration	   xi	     	   ea\n");
	printf("----------------------------------------------\n");


	while (1)
	{
		xrold = xr;
		xr = g(xrold);
		iter = iter + 1;

		if (xr != 0)
			ea = ABS((xr - xrold) / xr) * 100;

		printf("    %2d		%lf	", iter, xr);

		if (iter != 1)
			printf("%9lf\n", ea);
		else
			printf("\n");
		
		if (ea < 0.01)
		{
			printf("----------------------------------------------\n\n");
			printf("±Ù(x) : %lf\n\n", xr);
			break;
		}
	}
}

int main(void)
{
	double x0 = 5, ea = 0;
	Fixpt(x0, ea);
	return 0;
}