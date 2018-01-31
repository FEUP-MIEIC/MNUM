#include <stdio.h>
#define N 4

void showMatrix(double m[N][N+1]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N+1; j++) {
            printf("%13.5lf", m[i][j]);
        }

        printf("\n");
    }

    printf("\n\n\n");
}

// l1 = l1 - l2*coef
void rowOp(double m[N][N+1], int r1, int r2, double coef) {
    for(int j = 0; j < N+1; j++) {
        m[r1][j] -= m[r2][j]*coef;
    }
}

void gauss(double m[N][N+1]) {
    for(int i = 0; i < N; i++) {
        // dividir linha atual por aii, da diagonal principal
        rowOp(m, i, i, 1-1/m[i][i]);
        showMatrix(m);
        // "zerar" todos os elementos da coluna i, exceto aii
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            rowOp(m, j, i, m[j][i]);
            showMatrix(m);
        }

        
    }
}

int main() {
    double m[N][N+1] = {
        {0.01000, 0.50000, 3.00000, 0.25000, 19.00000},
        {1.20000, 0.01000, 0.25000, 0.20000, -2.20000},
        {-1.00000, 0.25000, 0.00001, 2.00000, 9.00000},
        {2.00000, 0.00001, 1.00000, 1.00000, 15.00000}
    };

    gauss(m);
}