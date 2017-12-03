#include <stdio.h>

/*
 @brief Assuming an ODE in the form y' = f(x,y), this function returns the value of f(x,y) for some point (x,y)
*/
double f_xy(double x, double y) {
    return x-2;
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

    /*
     I defined as ODE y'=x-2 which has a general solution y=x^2/2-2*x+C
     With the initial condition y=3 and x=0, the solution is y=(x^2-4*x+6)/2
    */
    double const h = 0.5; // step
    double const x = 2; // where to calculate the solution
    double const y0 = 3, x0 = 0; // initial conditions
    double const realSolution = 1;
    double I, I1, I2, conv_coef;

    I = euler_method(&f_xy, x, h, x0, y0);
    I1 = euler_method(&f_xy, x, h/2, x0, y0);
    I2 = euler_method(&f_xy, x, h/4, x0, y0);
    conv_coef = (I1-I)/(I2-I1); // Convergence coefficient. Euler's method is first order method, if this coef is 2 we likely have a good aproximation (or maybe not...)
    
    printf("h: %lf\tI:%lf\n", h, I);
    printf("h': %lf\tI':%lf\n", h/2, I1);
    printf("h'': %lf\tI'':%lf\n", h/4, I2);
    printf("Convergence coefficient: %lf\n", conv_coef);
    printf("Error estimation: %lf\n", I2-I1);
    printf("Real error: %lf\n", I2-realSolution);
}