#include "Gauss.h"
#include <stdio.h>

/*
 * @brief Mostra a matriz de forma formatada
 */
void showMatrix(float matrix[N][N+1])
{
    for(int i = 0; i < N; i++)
    {
        printf("{");
        for(int j = 0; j < N+1; j++)
        {
            printf(" %.5f ", matrix[i][j]);
        }
        printf("}\n");
    }

    printf("\n\n");
}

/*
 * @brief Multiplica uma linha por um escalar
 */
void rowOp_scalar(float m[N][N+1], int l1, float coef)
{
    for(int j = 0; j < N+1; j++)
            m[l1][j] *= coef;
}

/*
 *@brief Realiza a operacao entre linhas l1 = l1 + coef*l2
 */
void rowOp_addition(float m[N][N+1], int l1, int l2, float coef)
{
    for(int i = 0; i < N+1; i++)
    {
        m[l1][i] += coef*m[l2][i];
    }
}

/*
 * Resolve um sistema usando eliminação gaussiana
 */
void gauss(float m[N][N+1])
{
    for(int i = 0; i < N; i++)
    {
        rowOp_scalar(m, i, 1/m[i][i]); // dividir a linha pelo valor pivot

        for(int j = 0; j < N; j++)
        {
            if(i != j) rowOp_addition(m, j, i, -m[j][i]); // zerar a coluna do atual pivot
        }
    }
}