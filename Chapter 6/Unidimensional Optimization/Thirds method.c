#include <stdio.h>
#include <math.h>

#define PRECISION 0.00001

double f(double x)
{
    // Minimum at x= 3.6330
    return x * x * x - 6 * x * x + 4 * x + 12;
}

int main()
{
    double x1 = 2, x2 = 6;    // set the interval where the minimum is
    unsigned int counter = 0; // Iterations counter to compare with golde-section method

    // This loop uses a precision condition to stop
    while (fabs(x2 - x1) > PRECISION)
    {
        double d = fabs(x2 - x1) / 3,
               x3 = x1 + d,
               x4 = x1 + 2 * d,
               f3 = f(x3),
               f4 = f(x4);

        // Reduce the interval
        if (f4 < f3)
        {
            x1 = x3;
        }
        else
        {
            x2 = x3;
        }

        // update counter
        counter++;
    }

    printf("Minimum is located on [%lf, %lf]\n", x1, x2);
    printf("Iterations: %d\n", counter);
}