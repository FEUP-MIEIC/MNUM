#include <stdio.h>
#include <math.h>
double f(double x)
{
    return pow(cos(x + 1.2), 3) + x - 3.7;
}

double df(double x)
{
    return 1 - 3 * cos(x + 1.2) * cos(x + 1.2) * sin(x + 1.2);
}
int main()
{
    double x = 3.8;
    printf("%.4lf\n", -f(x) / df(x) + x);
}