#include <stdio.h>

double f(double u, double v) {
    return v*v*v*u*(u/2 + 1) + v*v*(u+5.0/2);
}

double RK4(double h, double u0, double uf, double v0) {
    for(int i = 0; i < (uf-u0)/h; i++) {
        double d1, d2, d3, d4;
        d1 = h*f(u0, v0);
        d2 = h*f(u0 + h/2, v0 + d1/2);
        d3 = h*f(u0 + h/2, v0 + d2/2);
        d4 = h*f(u0 + h, v0 + d3);
        v0 += d1/6 + d2/3 + d3/3 + d4/6;
        u0 += h;
    } 
}
int main() {
    double h = 0.08;
    double R = RK4(h,1, 1.8, 0.15);
    double R1 = RK4(h/2,1, 1.8, 0.15);
    double R2 = RK4(h/4,1, 1.8, 0.15);

    printf("h, v = %lf\n", R);
    printf("h', v = %lf\n", R1);
    printf("h'', v = %lf\n", R2);
    printf("QC: %lf\n", R1)
}