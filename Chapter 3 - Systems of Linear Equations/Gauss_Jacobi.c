#include <stdio.h>

int main() {
    /*
    Solving the following system
    * 7x + 2y = 24
    * 4x + 10y + z = 27
    * 5x - 2y + 8z = 27

    Notice that the convergence criterium is satisfied
    */

    // Initial guess
    double x = 0,
    y = 0,
    z = 0;

    for(int i = 0; i < 4; i++) {
        double xn = x, yn = y, zn = z; // preserve the results from previous iteration
        x = (24-2*yn)/7;
        y = (27-zn-4*xn)/10;
        z = (27-5*xn+2*yn)/8;
        printf("x: %lf\n", x);
        printf("y: %lf\n", y);
        printf("z: %lf\n\n", z);
    }

    
}