#include <stdio.h>
#include <math.h>

int main() {
    double x,y,z,w;
    x = y = z = w = 0; // guess inicial
    for(int i = 0; i < 2; i++) {
        x = (1+y+z-w)/4.8;
        y = (-1+x-z+w)/4.8;
        z = (-1+x-2*y+w)/4.8;
        w = (4.8-2*x+y+z)/4.8;

        printf("x:%.5lf\ty:%.5lf\tz:%.5lf\tw:%.5lf\n\n", x,y,z,w);
    }
}