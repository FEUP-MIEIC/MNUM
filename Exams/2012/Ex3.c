#include <stdio.h>

double f(double x, double y)
{
    return 3 * x * x - x * y + 11 * y + y * y - 8 * x;
}
double dfx(double x, double y)
{
    return 6 * x - y - 8;
}
double dfy(double x, double y)
{
    return -x + 11 + 2 * y;
}

int main()
{
    double x = 2, y = 2, h = 0.5;
    printf("x: %lf\ty: %lf\tZ(X): %lf\tGrad_x: %lf\tGrad_y: %lf\n", x, y, f(x,y), dfx(x,y), dfy(x,y));

    for(int i = 0; i < 1; i++) {
        double xn = x - h*dfx(x,y);
        double yn = y - h*dfy(x,y);

        // Since only one iteration is required, this could be omitted (except maybe to find the best delta)
        if(f(xn, yn) > f(x,y)) {
            h = h/2;
        }
        else {
            x = xn;
            y = yn;
            h *= 2;
            printf("x: %lf\ty: %lf\tZ(X): %lf\tGrad_x: %lf\tGrad_y: %lf\n", x, y, f(x,y), dfx(x,y), dfy(x,y));
        }
    }
}