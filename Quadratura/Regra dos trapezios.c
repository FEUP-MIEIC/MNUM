#include <stdio.h>

double f_x(double x)
{
    return x*x;
}

double primitive(double (*f)(double), double a, double b, int n)
{
    double h = (a+b)/n, x = a, I = 0;
    int i;
    for(i = 0; i <= n; i++)
    {
        if(i == 0 || i == n) 
            I += (*f)(x);
        else 
            I += 2 * (*f)(x);

        x += h;
    }

    I *= h/2;

    return I;

}
int main()
{
    double a, b; // range (a < b)
    int n;
    printf("a ? "); scanf("%lf", &a);
    printf("b ? "); scanf("%lf", &b);
    printf("Number of iterations ? "); scanf("%d", &n);

    printf("Result: %lf", primitive(&f_x, a, b, n));
}