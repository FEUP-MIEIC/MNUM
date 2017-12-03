#include <stdio.h>
#include <math.h>

/*
 @param f Funtion to integrate
 @param a 
 @param b
 @param n Number of iterations
 @return The value of integration
*/
double primitive(double (*f)(double), double a, double b, int n)
{
    double h = (a+b)/n, // calculate the x increment on each step
    I = 0;
    int i;

    
    for(i = 1; i <= n-1; i++)
    {
        /* 
            Note1: Instead of adding h to some variable at each iteration (x = a + h + h ...), which would cause a systematic error, use a+h*i. It's a much better approach
            Note2: Also, note that at each iteration I only add/subtract a function value. 
                    Multiplication is done after the loop, reducing the CPU instructions from N^2 to N
        */
        I += (*f)(a+h*i); 
    }

    // finish integral calculation
    I *= 2; // 2*y1+2*y2+...2*y(n-1) -> 2* [y1+y2+...+y(n-1)]
    I += (*f)(a) + (*f)(b); // add missing y0 and yn, which are not multiplied by 2. Note that it's better to use f(b) rather than f(a+h*n). Otherwise, the resultant integral might use a slice after/before x=b
    I *= h/2; // Apply last operation, multiply all elements by h/2. h/2*[y0 + 2y1 + 2y2 + ... + 2y(n-1) + yn]
    
    return I;

}

/*
 @brief This function estimates the error (lagrange theorem)
 @param a
 @param b
 @param ddf The absolute maximum value of the second derivate of the function to integrate, on the interval [a,b]
 @param n Number of steps on the integration
 */
double error(double ddf, double a, double b, double n) {
    /*
     If we know the second derivative of the function to integrate, we can estimate the integral error by applying
        e = - ((xn - x0)^3) / (12*n^2) * f''(csi),
        where xn and x0 are the integral interval, 
        n is the number of steps and 
        f''(csi) is the maximum absolute value of the second derivative on the integration interval (hence, the error is a upper bound)
     */

    return - pow((b-a),3)/(12*n*n) * ddf;
}

/*
 The function to integrate
 */
double f_x(double x)
{
    return sin(x);
}

int main()
{
    double a, b, I;
    int n;
    printf("a ? "); scanf("%lf", &a);
    printf("b ? "); scanf("%lf", &b);
    printf("Number of iterations ? "); scanf("%d", &n);

    /*
     As for an example, imagine you want to integrate sin(x) from 0 to pi/2
     For error estimation, the second derivate of sin(x) is -sin(x). The maximum absolute value on [0, pi/2] is 1 (ddf_sci), that's the value of ddf parameter
     For real error, I just subtract the calculated integral and the real solution (real_I), which is 1
    */
    double const ddf_sci = 1, real_I = 1;
    printf("Result: %E\n", I = primitive(&f_x, a, b, n));
    printf("Error estimation: %E\n", error(ddf_sci, a, b, n));
    printf("Error : %E\n", I-real_I);
}