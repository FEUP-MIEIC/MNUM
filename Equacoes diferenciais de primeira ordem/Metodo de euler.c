#include <stdio.h>

/*
 @brief Assuming an ODE in the form y' = f(x,y), this function returns the value of f(x,y) for some point (x,y)
*/
double f_xy(double x, double y) {
    return y;
}

/*
 @brief Find the solution for an ODE y'=f(x,y) at x using h as step
 @param f The f(x,y) from ODE written as y'=f(x,y)
 @param x Where to calculate the solution
 @param h Step. x(n+1) = xn + h
*/
double euler_method(double (*f)(double,double), double x, double h, double x0, double y0) {
    double xn = x0 + h, yn = y0 + (*f)(x0,y0)*h;
    
    //printf("x0: %lf, y0: %lf\n", x0, y0); 
    //printf("xn: %lf, yn: %lf\n\n", xn, yn);
    
    while(!(x <= xn && x >= x0)) {
        y0 = yn;
        x0 = xn;

        xn += h;
        yn = y0 + (*f)(x0,y0)*h;

        //printf("x0: %lf, y0: %lf\n", x0, y0); 
        //printf("xn: %lf, yn: %lf\n", xn, yn);
    }

    return y0 + (*f)(x0,y0)*(x-x0);
}
int main() {
    printf("%lf", euler_method(&f_xy, 2, 0.001, 0, 1));
}