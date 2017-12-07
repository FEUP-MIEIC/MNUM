#include <stdio.h>
#include <math.h>

#define PRECISION 0.00001

double f(double x) {
    return x*x;
}

int main() {
    // intervalo onde se encontra o minimo
    double a = -0.3, b = 5;
    int i;
    for(i = 0; fabs(b-a) > PRECISION ; i++) {
        double d = fabs(b-a)/3.0; // dividir o intervalo em 3
        double x1 = a+d, x2 = b-d;
        // a ... x1 ... x2 ... b
            if(f(x1) < f(x2)) // então rejeita-se  [x2, b] e assume-se [a, x2]
            b = x2;
        else // rejeita-se [a, x1] e assume-se o novo intervalo [x1, b]
            a = x1;

        printf("a: %lf\tb:%lf\n", a, b);
    }

    
    printf("Iteracoes: %d\n", i);
} 