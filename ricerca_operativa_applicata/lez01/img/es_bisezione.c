#include <math.h>
#include <stdio.h>

typedef double (*function)();

double
bisezione_min(function df, double l, double r, double epsilon) {
	double c;
	double dfc;
	int iterazione = 0;

	c = (l+r)/2;
	printf("Inizializzazione:\n  $\\underbar{x} = %5g$,\n  $\\bar{x} = %5g$,\n  $x'=%5g$.\n\nIterazioni:\n\\begin{enumerate}\n", l, r, c);

	while ((r - l) > 2 * epsilon) {
		dfc = df(c);
		if (dfc >= 0.)
			r = c;
		if (dfc <= 0.)
			l = c;
		c = (l + r) / 2;
		printf("\\item[%2d.]\n  $f'(x') = %5g$,\n  $\\underbar{x} = %5g$,\n  $\\bar{x} = %5g$, $x' = %5g$.\n", iterazione++, dfc, l, r, c);
	}
	printf("\\end{enumerate}\n\n");

	return c;
}

double f(double x) {
	return x * sin(4*x);
}

double df(double x) {
	return sin(4*x)+4*x*cos(4*x);
}

int
main() {
	double min;
	printf("\\documentclass[a4paper]{article}\n\\begin{document}\n");
	min = bisezione_min(df, 2.75, 3, 0.000001);
	printf("Soluzione:\n  $x^* = %5g$,\n  $f(x^*) = %5g$,\n  $f'(x^*) = %5g$.\n", min, f(min), df(min));
	printf("\\end{document}\n");
	
	return 0;
}
