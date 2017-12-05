#include <stdio.h>
#include <math.h>
#define Nx 4
#define Ny 4

double f(double x, double y) {
    return x*y;
}

double primitive_simpson_extended(double (*f)(double, double), double xa, double xb, double ya, double yb, int nx, int ny) {
    double hx = fabs(xb-xa)/nx;
    double hy = fabs(yb-ya)/ny;
    double I = 0;
    for(int i = 0; i <= ny; i++) {
        // determine Ix
        double Ix = f(xa, ya+hy*i) + f(xb, ya+hy*i);
        for(int j = 1; j <= nx-1; j++) {
            if(j%2 == 0) {
                Ix += 2*f(xa+hx*j, ya+hy*i);
            } else {
                Ix += 4*f(xa+hx*j, ya+hy*i);
            }
        }

        Ix = hx*Ix/3;


        if(i == 0){
            I += Ix;
        }
        else if(i == ny) {
            I += Ix;
        }
        else if(i%2 != 0)
            I += 4*Ix;
        else 
            I += 2*Ix;
    }

    I *= (hy/3);

    return I;
}

int main(){
    printf("%lf", primitive_simpson_extended(&f, 0, 2, 0, 2, 4, 4));
}