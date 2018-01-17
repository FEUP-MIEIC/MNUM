#include <stdio.h>
#include <math.h>

#define NEPER 2.71828182

double f(double x) {
    return pow(NEPER, 1.5*x);
}

double simpson(double h, double a, double b) {
    double sum = f(a) + f(b);

    // Exludes first and last point, already used to initialize 'sum'
    for(int i = 1; i <= fabs(b-a)/h - 1; i++) {
        if(i % 2 == 0) 
            sum += 2*f(a+h*i);
        else 
            sum += 4*f(a+h*i);
    }

    return h/3*sum;
}

int main() {
    double const a = 1;
    double const b = 1.5;
    double const h = 0.125;

    double S = simpson(h, a, b);
    double S1 = simpson(h/2, a, b);
    double S2 = simpson(h/4, a, b);

    /**
     * a)
     */
    printf("h: %.5lf\tS: %.5lf\n", h, S);
    printf("h: %.5lf\tS: %.5lf\n", h/2, S1);
    printf("h: %.5lf\tS: %.5lf\n", h/4, S2);

    printf("QC: %.5lf\n", (S1-S)/(S2-S1));
    printf("Erro relativo: %.10lf\n", (S2-S1)/15);
}