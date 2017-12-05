#include <stdio.h>
#include <math.h>

#define NEPER 2.718281828459045
#define a 20.0
#define b 0.5

double func_C(double t, double C, double T) {
    return -pow(NEPER, -b/(T+273))*C;
}

double func_T(double t, double T, double C) {
    return a*pow(NEPER, -b/(T+273))*C - b*(T-20);
}

int main() {
    double t = 0, C = 2.0, T = 20.0;
    double const h = 0.2;
    /*
        4. a)
    */
    printf("a)\nEULER\n");
    for(int i = 0; i < 2; i++) {
        double aux = C;
        C = C + h*func_C(t,C,T);
        T = T + h*func_T(t, T, aux);
        t += h;
        printf("t: %.6lf\tC: %.6lf\tT: %.6lf\n", t, C, T);
    }

    /*
        4. b)
    */
    printf("\n\nb)\nRK4\n");
    t = 0, C = 2.0, T = 20.0;
    for(int i = 0; i < 2; i++) {
        double aux = C;
        double d1,d2,d3,d4;
        // Calculate C(n+1)
        d1 = h*func_C(t,C,T);
        d2 = h*func_C(t+h/2, C+d1/2, T);
        d3 = h*func_C(t+h/2, C+d2/2, T);
        d4 = h*func_C(t+h, C+d3, T);
        C = C + d1/6 + d2/3 + d3/3 + d4/6;

        // Calculate T(n+1)
        d1 = h*func_T(t,T,C);
        d2 = h*func_T(t+h/2, T+d1/2, C);
        d3 = h*func_T(t+h/2, T+d2/2, C);
        d4 = h*func_T(t+h, T+d3, C);
        T = T + d1/6 + d2/3 + d3/3 + d4/6;

        // update t
        t += h;
        printf("t: %.6lf\tC: %.6lf\tT: %.6lf\n", t, C, T);
    }


    /*
        4.c
    */
    double C1 = 2.0, C2 = 2.0;

    // with h' = h/2
    t = 0, T = 20.0;
    for(int i = 0; i < 2; i++) {
        double aux = C1;
        C1 = C1 + h/2*func_C(t,C1,T); 
        T = T + h*func_T(t, T, aux);
        t += h;
    }

    // with h'' = h/4
    t = 0, T = 20.0;
    for(int i = 0; i < 2; i++) {
        double aux = C2;
        C2 = C2 + h/4*func_C(t,C1,T);
        T = T + h*func_T(t, T, aux);
        t += h;
    }

    printf("\n\nc)\n");
    printf("h':%.5lf\n", h/2);
    printf("h':%.5lf\n", h/4);
    printf("C':%.5lf\n", C1);
    printf("C'':%.5lf\n", C2);
    printf("QC:%.5lf\n", (C1-C)/(C2-C1));
    printf("erro:%.5lf\n", C2-C1); // first order method
}