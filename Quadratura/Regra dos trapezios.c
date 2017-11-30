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

    
    for(i = 1; i <= n-1; i++)
    {
        I += (*f)(x);
        
        *e -= (*g)(x);
        
        x += h;
    }

    // finish integral calculation
    I *= 2; // 2*y1+2*y2+...2*y(n-1) -> 2* [y1+y2+...+y(n-1)]
    I += (*f)(a) + (*f)(b); // add missing y0 and yn
    I *= h/2; // h/2*[y0 + 2y1 + 2y2 + ... + 2y(n-1) + yn]

    // finish calculating the error
    *e -= (*g)(a) - (*g)(b); // subtract missing f''(a) and f''(b). NOTE: g(x) is the second derivative of f
    *e *= (h*h*h/12);
    

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