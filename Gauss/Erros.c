#include "Gauss.h"
#include <stdio.h>
#include <string.h>

void erroExterno(float m[N][N+1], float x0[N], float dA, float dB)
{
    /*
     * pretende-se resolver m*dX = dB - dA*x0
     * m é a matriz inicial
     * x0 é a matriz coluna com as solucoes do sistema
     * 
     * Entao, dX = [ [m] | [dB - dA*x0]]
     */

    for(int i = 0; i < N; i++) // inserir valores corretos na ultima coluna de m
    {
        m[i][N] = dB - dA*x0[i];
    }

    showMatrix(m);

    // aplicar gauss para calcular dX
    gauss(m);

    // mostrar resultado
    showMatrix(m);
}

int main()
{
    ///////////////////////////////////
    float m[N][N+1] = {
        {1.005, 1.005, 1.005, 111.555},
        {0.999, 1.004, 1.005, 111.539},
        {1.001, 1.003, 1.005, 111.531}
    };
    float x0[N];
    ///////////////////////////////////

    // cópias da matriz original
    float m2[N][N+1];
    memcpy(m2, m, N*(N+1)*sizeof(float));

    // resolver o sistema e definir uma matriz coluna x0 com solucoes do sistema
    gauss(m);
    showMatrix(m);
    for(int i = 0; i < N; i++)
        {x0[i] = m[i][N]; printf("%f\n", x0[i]);}
    
    ///////////////
    // erro externo
    ///////////////

    // assumindo o erro dos coefs na matriz A como 0.1 e na matriz B como 0.2
    
    float dB = 0.2f, dA = 0.1f;
    erroExterno(m2, x0, dA, dB);


    // erro interno
    
}