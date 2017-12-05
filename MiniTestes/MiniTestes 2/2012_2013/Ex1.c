#include <stdio.h>

int main(){
    double x,y,z,w;
    x = y = z = w = 0.25; // guess
    for(int i = 0; i < 2; i++) {
        double xn = x, yn = y, zn = z, wn = w; // preserve current values
        x = (1+yn+zn-wn)/4.5;
        y = (-1+xn-zn+wn)/4.5;
        z = (-1+xn-2*yn+wn)/4.5;
        w = (-2*xn+yn+zn)/4.5;

        printf("x:%.5lf\ny:%.5lf\nz:%.5lf\nw:%.5lf\n\n\n", x, y, z, w);
    }
}