#include <stdio.h>
#include <math.h>

double f(double x) {
    return x-1.8 + pow(cos(x+0.1),3);
}

double df(double x) {
    return 1.0-3.0*cos(x+0.1)*cos(x+0.1)*sin(x+0.1);
}
int main() {
    double x0 = 3.7;

    double x1 = x0 - f(x0)/df(x0);

    printf("x1: %.5lf", x1);
}