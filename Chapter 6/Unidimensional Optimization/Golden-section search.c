#include <stdio.h>
#include <math.h>

#define B (sqrt(5) - 1) / 2.0 // golden ratio
#define A B *B
#define PRECISION 0.00001

double f(double x)
{
	// Minimum at x= 3.6330
	return x * x * x - 6 * x * x + 4 * x + 12;
}

int main()
{
	// set interval where minimum is located and pre-compute the function on the extremes
	double x1 = 2,
		   x2 = 6,
		   x3 = A * (x2 - x1) + x1,
		   x4 = B * (x2 - x1) + x1,
		   f3 = f(x3),
		   f4 = f(x4);

	unsigned int counter = 0;

	// This loop uses a precision condition to stop
	while (fabs(x2 - x1) > PRECISION)
	{
		if (f3 < f4)
		{
			x2 = x4;
			x4 = x3;
			x3 = A * (x2 - x1) + x1;
			f4 = f3;
			f3 = f(x3);
		}
		else
		{
			x1 = x3;
			x3 = x4;
			x4 = B * (x2 - x1) + x1;
			f3 = f4;
			f4 = f(x4);
		}

		counter++;
	}

	printf("Minimum is located on [%lf, %lf]\n", x1, x2);
	printf("Iterations: %d\n", counter);
}