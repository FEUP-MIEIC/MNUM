#include <stdio.h>

double f(double u, double v) {
    // 5.0/2.0 to make floating point division...
    return (u/2.0+1)*v*v*v*u + (u+5.0/2.0)*v*v;
}

double euler(double h) {
    double v = 0.1, u = 1.0; //condicoes inicias
    
    // determine 
    while((1.8 > u-h && u <= 1.8)) {
        v = v + f(u,v)*h;
        u += h;
    }

    printf("u:%lf\n", u);
    return v;
}
int main() {
    double h  = 0.08;
    
    // v com h
    double v = euler(h);

    // v com h'
    double v1 = euler(h/2);

    // v com h''
    double v2 = euler(h/4);

    // output
    printf("h: %.6lf\tv(1.8): %.6lf\n", h, v);
    printf("h': %.6lf\tv(1.8): %.6lf\n", h/2, v1);
    printf("h'': %.6lf\tv(1.8): %.6lf\n", h/4, v2);
    printf("QC: %.6lf\n", (v1-v)/(v2-v1));
    printf("Erro: %.6lf\n", v2-v1); // euler é um metodo de primeira ordem
    
}