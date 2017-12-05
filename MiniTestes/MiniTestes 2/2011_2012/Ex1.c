#include <stdio.h>
#include <math.h>

int main() {
    double f[3][3] = {
        {1.1, 1.4, 2.6}, // y = 0
        {2.1, 4.9, 2.2}, // y = 0.9
        {6.3, 1.5, 1.2} // y = 1.8
    };
    
    double h = 0.9, x0 = 0, y0 = 0, I = 0;

    for(int i = 0; i < 3; i++) {
        double Ix = f[i][0] + 4*f[i][1] + f[i][2]; // because it's only three steps, there's no need for a loop..
        Ix *= h/3;

        if(i == 0 || i == 2)
            I += Ix;
        else
            I += 4*Ix; // again, three steps, I will omit the case with coefficient 2
    }

    I *= h/3;
    printf("%lf", I); 
}