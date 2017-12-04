#include <stdio.h>
#include <math.h>

double f(double t, double x) {
    return sin(2*x) + sin(2*t);
}

double RK4(double h) {
    double x=1.0,t=1.0;
    while(t < 1.5) {
        double d1,d2,d3,d4;
        d1 = h*f(t,x);
        d2 = h*f(t+h/2, x+d1/2);
        d3 = h*f(t+h/2, x+d2/2);
        d4 = h*f(t+h, x+d3);

        x = x + d1/6 + d2/3 + d3/3 + d4/6;
        t = t + h;
        printf("t: %.6lf\tx: %.6lf\n", t,x);
    }
    printf("\n\n");
    return x;
}

int main(){
    printf("h=0.5\n");
    double I = RK4(0.5);
    
    printf("h=0.250\n");
    double I1 = RK4(0.250);
    
    printf("h=0.125\n");
    double I2 = RK4(0.125);

    printf("Quociente convergencia: %.6lf\n", (I1-I)/(I2-I1));
}

/*
    2.c)
    Como o método é de 4ª ordem, se h=0.125 fosse um bom passo de integração, o quociente seria aproximadamente 16, o que não se verifica
    Então, usuaria h=0.125/2=0.0625
*/