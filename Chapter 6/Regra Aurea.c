#include <stdio.h>
#include <math.h>

#define B (sqrt(5)-1)/2.0 // numero de ouro
#define A B*B
#define PRECISION 0.00001

double f(double x) {
    return x*x;
}

int main() {
    // intervalo onde se encontra o minimo
    double a = -0.3, b = 5;
    int i;
    double x1 = A*(b-a) + a, 
            x2 = B*(b-a) + a;
    for(i = 0; fabs(b-a) > PRECISION ; i++) {
        if(f(x1) < f(x2)) // minimo está em [a, x2]
        {
            b = x2;
            x2 = x1;
            x1 = B*(x2-a) + a;
        }
        else
        {
            a = x1;
            x1 = x2;
            x2 = B*(b-x1) + x1;
        }
            
        printf("a: %lf\tb:%lf\n", a, b);
    }

    printf("Iteracoes: %d\n", i);
}