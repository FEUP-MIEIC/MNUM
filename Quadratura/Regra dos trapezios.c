#include <stdio.h>
#include <math.h>

double f_x(double x) // f(x)
{
    return sin(x);
}
double f_dx2(double x) // f''(x)
{
    return -sin(x);
}

/*
    @param f Funtion to integrate
    @param g The second derivative of the function to integrate
    @param a 
    @param b
    @param n Number of iterations
    @param *e Pointer to a variable that will be assigned with the numeric error
    @return The value of integration
*/
double primitive(double (*f)(double), double (*g)(double), double a, double b, int n, double *e)
{
    double h = (a+b)/n, x = a, I = 0;
    *e = 0; // error
    int i;
    for(i = 0; i <= n; i++)
    {
        if(i == 0 || i == n) 
            I += (*f)(x);
        else 
            I += 2 * (*f)(x);
        
        *e -= (h*h*h/12)*(*g)(x);
        
        x += h;
    }

    I *= h/2;

    return I;

}
int main()
{
    double a, b; // range (a < b)
    int n;
    double error;
    printf("a ? "); scanf("%lf", &a);
    printf("b ? "); scanf("%lf", &b);
    printf("Number of iterations ? "); scanf("%d", &n);

    printf("Result: %E\n", primitive(&f_x, &f_dx2, a, b, n, &error));
    printf("Error: %E\n", error);    
}