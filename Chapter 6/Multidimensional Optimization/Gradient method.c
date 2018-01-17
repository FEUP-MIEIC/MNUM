#include <stdio.h>
#include <math.h>

#define PRECISION 0.001

double fxy(double x, double y)
{
    return 12 * y * y + 7 * x * x - 8 * x;
}

double dfx(double x, double y)
{
    return 14 * x - 8;
}

double dfy(double x, double y)
{
    return 24 * y;
}

int main()
{
    double h = 1,
           x = 20,
           y = 2,
           f,
           fn;

    do
    {
        double xn = x - h * dfx(x, y),
               yn = y - h * dfy(x, y);

        f = fxy(x, y);
        fn = fxy(xn, yn);

        if (fn > f)
        {
            // step back and reduce the step h
            h /= 2;
        }
        else
        {
            // Update the coordinates and double the step
            printf("%lf\t%lf\n", xn, yn);
            x = xn;
            y = yn;
            h *= 2;
        }

    } while (fabs(fn - f) > PRECISION);
}