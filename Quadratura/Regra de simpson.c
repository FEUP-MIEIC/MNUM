#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f_x(double x) {
    return sin(x);
}

double primitive_simpson(double (*f)(double), double a, double b, int n) {
    int i;
    double h = (b-a)/n;
    double I = (*f)(a) + (*f)(b);
    for(i = 1; i <= n-1; i++) {
        if(i%2 != 0)
            I += 4*(*f)(a+h*i);
        else 
            I += 2*(*f)(a+h*i);
    }

    I *= h/3;

    return I;
}
int main() {
    double a,b; // integration range
    int n; // number of intervals


    printf("a ? ");
    scanf("%lf", &a);

    printf("b ? ");
    scanf("%lf", &b);

    printf("Intervals ? ");
    scanf("%d", &n);

    printf("I = %E\n", primitive_simpson(&f_x,a,b,n));
}