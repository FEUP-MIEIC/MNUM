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
            This is needed to calculate the error, applying h^3/12 * SUM(-f''(xn)). On this case the f'' is known, therefore this is possible
    @param a 
    @param b
    @param n Number of iterations
    @param *e Pointer to a variable that will be assigned with the numeric error
    @return The value of integration
*/
double primitive(double (*f)(double), double (*g)(double), double a, double b, int n, double *e)
{
    double h = (a+b)/n, // calculate the x increment on each step
    I = 0;
    *e = 0; // error
    int i;

    
    for(i = 1; i <= n-1; i++)
    {
        /* 
            Note1: Instead of adding h to some variable at each iteration, which would cause a systematic error, do a+h*i. It's a much better aproach
            Note2: Also, note that at each iteration I only add/subtract a function value. 
                    Multiplication is done after the loop, reducing the CPU instructions from N^2 to N
            Note3: g is the second derivative of f
        */
        I += (*f)(a+h*i); 
        
        *e -= (*g)(a+h*i);
    }

    // finish integral calculation
    I *= 2; // 2*y1+2*y2+...2*y(n-1) -> 2* [y1+y2+...+y(n-1)]
    I += (*f)(a) + (*f)(b); // add missing y0 and yn, which are not multiplied by 2. Also note that it's better to use f(b) rather than f(a+h*n), again error reduction
    I *= h/2; // Apply last common operation to all elements. h/2*[y0 + 2y1 + 2y2 + ... + 2y(n-1) + yn]

    // finish error calculation
    *e -= (*g)(a) - (*g)(b); // subtract missing f''(a) and f''(b). 
    *e *= (h*h*h/12); // multiply by the common factor
    

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