#include <math.h>
#include <stdio.h>

typedef double (*function)();

double
newton(function f, function df, double x, double epsilon) {
	double x_p = x + 3*epsilon;
	// double dfx;
	int iterazione = 0;

	printf("Inizializzazione:\n  ${x_0} = %5g$.\n\nIterazioni:\n\\begin{enumerate}\n", x);

	while (abs((x - x_p)) > 2 * epsilon) {
		x_p = x;
		x = x - f(x)/df(x); 
		printf("\\item[%2d.]\n  $x=%5g$\n  $f(x) = %5g$.\n", ++iterazione, x, f(x));
	}
	printf("\\end{enumerate}\n\n");

	return x;
}

double f(double x) {
	return x * sin(4*x);
}

double df(double x) {
	return sin(4*x)+4*x*cos(4*x);
}

double d2f(double x) {
	return 8*cos(4*x)-4*x*sin(4*x);
}

int
main() {
	double x;
	printf("\\documentclass[a4paper]{article}\n\\begin{document}\n");
	x = newton(df, d2f, 2.5, 0.000001);
	printf("Soluzione:\n  $x = %5g$,\n  $f(x^*) = %5g$.\n", x, f(x));
	printf("\\end{document}\n");
	
	return 0;
}
