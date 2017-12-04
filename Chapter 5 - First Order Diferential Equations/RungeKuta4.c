#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return x*y;    
}

int main() {
    double x=1, y=1, h=0.5;
    for(int i = 0; i < 7; i++) {
        double d1 = h*f(x, y),
        d2 = h*f(x+h/2,y+d1/2),
        d3 = h*f(x+h/2, y+d2/2),
        d4 = h*f(x+h, y+d3);

        y = y + d1/6 + d2/3 + d3/3 + d4/6;
        x = x + h;
        printf("xn: %.6lf\tyn: %.6lf\n", x, y);
    }
}