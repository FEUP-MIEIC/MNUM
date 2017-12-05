#include <stdio.h>

void rowOp(double m[3][4], int r1, int r2, double coef) {
    // r1 = r1 - coef*r2
    for(int i = 0; i < 4; i++) {
        m[r1][i] -= coef*m[r2][i];  
    }
}

void show(double m[3][4]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j<4; j++)
            printf("%.4lf  ", m[i][j]);

        printf("\n");
    }

    printf("\n\n");
}

void gauss(double m[3][4]) {
    
    for(int i = 0; i < 3; i++) {
        // fazer elemento da diagonal principal 1
        rowOp(m, i, i, 1-1/m[i][i]);

        // por elementos acima e abaixo de m[i][i] a zero
        for(int j = 0; j < 3; j++){
            if(j == i) continue;
            rowOp(m, j, i, m[j][i]);
        }
    }
}

int main()
{
    double m[3][4] = {
        {0.7, 8, 3, 12},
        {-6, 0.45, -0.25, 15},
        {8,-3.1, 1.05, 23}
    };

    gauss(m);
    printf("Solucao do sistema\n");
    show(m);
    printf("\n\n");


    // estabilidade externa
    /* 
        calcular db - dA.x, em que dB é matriz coluna preenchida com 0.5, e dA é uma matriz 3x3 preenchida com 0.5. 
        O produto por 'x' resulta noutra matriz coluna, com elementos iguais
    */
    double db, dA;
    db = dA = 0.5;
    double aux = db-dA*(m[0][3]+m[1][3]+m[2][3]); // o valor dos elementos da matriz coluna db - dA.x

    double m2[3][4] = {
        {0.7, 8, 3, aux},
        {-6, 0.45, -0.25, aux},
        {8,-3.1, 1.05, aux}
    };
    printf("Estabilidade externa\n");
    gauss(m2);
    show(m2);
}