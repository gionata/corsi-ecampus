#include <stdio.h>
#include <math.h>

int main()
{
	const char *colors[] =
	{
		"black",
		"yellow",
		"orange",
		"red",
		"ccqqqq",
		"lime",
		"green",
		"blue",
		"black"
	};
	int j=0;
	float m, em, x, y;

	for(m = -2.; m >= -4; m-=.25) {
		const float mod = 100;
		em = -1./m;
		x=(mod)/(1+em*em);
		y=em*x;
		x+=25;
		y+=60;

		printf("\\draw [->,color=%s] (25,60) --(%.2f, %.2f);\n", colors[j], x, y);
		x=(mod*1.30)/(1+em*em);
		y=em*x;
		x+=25;
		y+=60+(m+3.0)*(10);
		printf("\\draw[color=%s] (%.2f,%.2f) node {$m = %.2f$};\n", colors[j], x, y, m);
		j++;

	}

	return 0;
}
