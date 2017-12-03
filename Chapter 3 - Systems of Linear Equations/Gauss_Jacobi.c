#include <stdio.h>
#include <math.h>

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
        printf("x: %.6lf\tResiduo: %.6lf\n", x, fabs(24 - 7*x - 2*y));
        printf("y: %.6lf\tResiduo: %.6lf\n", y, fabs(27 - 4*x - 10*y - z));
        printf("z: %.6lf\tResiduo: %.6lf\n\n", z, fabs(27 - 5*x + 2*y - 8*z));
    }

    
}