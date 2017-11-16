#include <iostream>
#define N 3

using namespace std;

float matrix[3][4] = {
    {2,2,2,12},
    {1,2,4,17},
    {2,1,2,10}
};

void printMatrix()
{
    for(size_t i = 0; i < N; i++)
    {
        for(size_t j = 0; j < N+1; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}
int main()
{

    for(size_t i = 0; i < N; i++) // para cada elemento na diagonal principal
    {
        float pivot = matrix[i][i];
        matrix[i][i] = 1;

        for(size_t j = i+1; j < N+1; j++) // para cada elemento da linha dividir pelo pivot da linha
        {
            matrix[i][j] /= pivot;
        }

        cout << "Matriz apos dividir linha " << i+1 << " pelo pivot!" << endl;
        printMatrix();

        // zerar os elementos abaixo de A(i,i)
        
        for(size_t j = i+1; j < N; j++) // para todas as linhas abaixo da linha i
        {
            float lambda = matrix[j][0];
            for(size_t k = i; k < N+1; k++) // percorrer os elementos da linha j e fazer [j] = [j] - lambda*[i]
            {
                matrix[j][k] -= (matrix[i][k] * lambda);
            }
        }

        printMatrix();

    }

    // matriz está triangular, calcular soluções


}