#include <stdio.h>
#include <math.h>

#define NEPER 2.718281828459045
#define k 1.5

double f(double x) {
    return sqrt(1+k*k*pow(NEPER, x*k*2));
}

double trapezium(double h) {
    const double a = 0, b = 1;
    int n = (b-a)/h;
    double I = f(a)+f(b);
    for(int i = 1; i <= n-1; i++) {
        I += 2*f(a+h*i);
    }

    return I*h/2;
}

double simpson(double h) {
    
    const double a = 0, b = 1;
    int n = (b-a)/h;
    double I = f(a)+f(b);
    for(int i = 1; i <= n-1; i++) {
        if(i%2==0)
            I += 2*f(a+h*i);
        else 
            I += 4*f(a+h*i);
    }

    return I*h/3;
}

int main() {
    double h=0.25;

    // Trapezio
    printf("TRAPEZIO\n");
    double T = trapezium(h), T1 = trapezium(h/2), T2 = trapezium(h/4);
    printf("I: %.5lf\n", T);
    printf("I': %.5lf\n", T1);
    printf("I'': %.5lf\n", T2);
    printf("QC: %.5lf\n", (T1-T)/(T2-T1));
    printf("Erro: %.5lf\n", (T2-T1)/3);

    // Simpson
    printf("Simpson\n");
    double S = simpson(h), S1 = simpson(h/2), S2 = simpson(h/4);
    printf("I: %.5lf\n", S);
    printf("I': %.5lf\n", S1);
    printf("I'': %.5lf\n", S2);
    printf("QC: %.5lf\n", (S1-S)/(S2-S1));
    printf("Erro: %.5lf\n", (S2-S1)/15);
}