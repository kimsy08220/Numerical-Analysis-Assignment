#include <stdio.h>

double ABS(double x) {
	return x < 0 ? -x : x;
}
double f(double x){
	return -25 + 82 * x - 90 * x * x + 44 * x * x * x - 8 * x * x * x * x + 0.7 * x * x * x * x * x;
}

int main(void)
{
	double xrold = 0, xr = 0, xl = 0.5, xu = 1.0, es = 10, ea = 0, test = 0, fl = 0, fr = 0;
	int imax = 100, iter = 0;
	fl = f(xl);

	printf("				[Bisect result]\n");
	printf("----------------------------------------------------------------------------\n");
	printf("Iteration	   xl	     	   xu	     	   xr	     	   ea\n");
	printf("----------------------------------------------------------------------------\n");

	do {
		xrold = xr;
		xr = (xl + xu) / 2;
		fr = f(xr);
		iter = iter + 1;

		printf("    %d		%lf	%lf	%lf	", iter, xl, xu, xr);

		if (xr != 0)
			ea = ABS((xr - xrold) / xr) * 100;
		test = fl * fr;
		if (test < 0)
			xu = xr;
		else if (test > 0) {
			xl = xr;
			fl = fr;
		}
		else
			ea = 0;

		if (iter != 1)
			printf("%9lf\n", ea);
		else
			printf("\n");

		if (ea < es || iter >= imax) {
			printf("----------------------------------------------------------------------------\n\n");
			printf("±Ù(xr) : %lf\n\n", xr);;
			break;
		}
	} while (1);
	return 0;
}