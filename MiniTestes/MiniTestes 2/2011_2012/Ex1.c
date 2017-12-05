#include <stdio.h>
#include <math.h>

int main() {
    double f[3][3] = {
        {1.1, 1.4, 2.6},
        {2.1, 4.9, 2.2},
        {6.3, 1.5, 1.2}
    };
    
    double h = 0.9, x0 = 0, y0 = 0, I = 0;

    for(int i = 0; i < 3; i++) {
        if(i == 0 || i == 2)
            I = (y0+h*i)*
    }
}