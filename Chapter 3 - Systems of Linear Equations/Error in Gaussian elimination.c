#include <stdio.h>
#define N 3

/////////////////////////////////////////////////////////////////////////////////
// Based on http://def.fe.up.pt/numericos/sistemas_equacoes.html by Jaime Villate
/////////////////////////////////////////////////////////////////////////////////

/*
    @brief Applies operations over two matrix rows. l1 = l1 - coef*l2
    @param m Matrix
    @param l1 Index of first row
    @param l2 Index of the second row
    @param coef Scalar coefficient for second row 
*/
void rowOp(float m[N][N+1], int r1, int r2, float coef) {
    for(int j = 0; j < N+1; j++) { // iterate throw rows elements
        m[r1][j] -= coef*m[r2][j]; 
    }
}

/*
    @brief Auxiliar function to display the matrix
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
    @brief Applies gaussian elimination over a matrix with N lines and N+1 collumns
*/
void gauss(float m[N][N+1]) {
    /*
        This first loop will move along every matrix row
    */
    for(int i = 0; i < N; i++) {
        /*
            The first step is to make the element on the main diagonal, aii, equal to 1
            We have a function, rowOp, that makes operations over rows. L1 <- L1 - coef*L2.
            We can use that function to make elements aii equal to 1
            L1 - x*L1 = 1 <=> 1-x = 1/L1 <=> x = 1 - 1/L1 
        */
        rowOp(m, i, i, 1-1/m[i][i]);


        /*
            The next step is to make all the elements above/below aii equal to zero, again through rows operations
        */
        for(int j = 0; j < N; j++) {
            if(j == i) continue;
            rowOp(m, j, i, m[j][i]);
        }
    }
}

int main() {
    float m1[N][N+1] = {
        {7,8,9,24},
        {8,9,10,27},
        {9,10,8,27}
        };

    float m2[N][N+1] = {
        {7,8,9,24},
        {8,9,10,27},
        {9,10,8,27}
        }; // a copy of the original matrix, will be usefull for error estimation
    
    // Calculate the solution
    printf("System solution\n");
    gauss(m1);
    showMatrix(m1);

    /*
        Error estimation (external stability)
        The matrix m1 has the system solution on the column N
        To calculate the error, we want to solve A.dX = dB + dA.x0, where x0 is the system solution (collumn matrix),
            dA is a NxN matrix filled with error deltaA and dB is a collumn matrix filled with error deltaB
        I am going to use the matrix m2, a copy of the original, because the coefficients are needed (A in the formula). 
            Then I will just update the fourth collumn, with dB + dA.x0
        Afterwards, we apply gauss method to m2 and obtain a solution that tells us how deltaA and deltaB affect the system solution
    */
    const float dA = 0.5f, dB = 0.5f;

    // calculate dA*x0
    float aux = 0;
    for(int k = 0; k < N; k++)
        aux += m1[k][N]*dA;
    
    // update m2 last collumn
    for(int j = 0; j < N; j++) {
        m2[j][N] = dB - aux;
    }
    printf("External stability\n");
    gauss(m2);
    showMatrix(m2);
    
}