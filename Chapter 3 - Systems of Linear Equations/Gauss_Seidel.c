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
        x = (24-2*y)/7;
        y = (27-z-4*x)/10;
        z = (27-5*x+2*y)/8;
        printf("x: %lf\n", x);
        printf("y: %lf\n", y);
        printf("z: %lf\n\n", z);
    }

    
}