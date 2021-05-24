#include <stdio.h>

double ABS(double x) {
	return x < 0 ? -x : x;
}
double f(double x) {
	return -25 + 82 * x - 90 * x * x + 44 * x * x * x - 8 * x * x * x * x + 0.7 * x * x * x * x * x;
}

int main(void)
{
	double xrold = 0, xr = 0, xl = 0.5, xu = 1.0, es = 0.2, ea = 0, test = 0, fl = 0, fr = 0, fu = 0; 
	int imax = 100, iter = 0, iu = 0, il = 0;
	fl = f(xl);
	fu = f(xu);

	printf("				[ModFalsePos result]\n");
	printf("----------------------------------------------------------------------------\n");
	printf("Iteration	   xl	     	   xu	     	   xr	     	   ea\n");
	printf("----------------------------------------------------------------------------\n");

	do {
		xrold = xr;
		xr = xu - fu * (xl - xu) / (fl - fu);
		fr = f(xr);
		iter = iter + 1;

		printf("    %d		%lf	%lf	%lf	", iter, xl, xu, xr);

		if (xr != 0)
			ea = ABS((xr - xrold) / xr) * 100;
		test = fl * fr;
		if (test < 0) {
			xu = xr;
			fu = f(xu);
			iu = 0;
			il = il + 1;
			if (il >= 2)
				fl = fl / 2;
		}
		else if (test > 0) {
			xl = xr;
			fl = fr;
			il = 0;
			iu = iu + 1;
			if (iu >= 2)
				fu = fu / 2;
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