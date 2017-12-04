#include <stdio.h>
#include <math.h>
#define Nx 4
#define Ny 4

double f_x(double x)
{
    return x;
}

double f_y(double y)
{
    return y;
}

double primitive_simpson(double (*f)(double), double a, double b, int n) {
    int i;
    double h = fabs(b-a)/n;
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

int main(){
    double const hx = 0.5, hy = 0.5;
    double Iy = 0; 
    double Ix = primitive_simpson(&f_x, 0, 2, 4); // the area is retangular, so I want to do Iy * Ix, Ix is equal for every dy
    double y = 0;
    for(int i = 1; i <= 3; i++) {
        if(i % 2 == 0)
            Iy += 2*Ix*(y+hy*i);
        else
            Iy += 4*Ix*(y+hy*i);
    }

    // add the two extremas, y=a and y=b
    Iy += 0*Ix;
    Iy += 2*Ix;
    Iy *= hy/3;

    printf("%lf", Iy);
}