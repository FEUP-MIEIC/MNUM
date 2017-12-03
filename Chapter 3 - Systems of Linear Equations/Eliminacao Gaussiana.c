#include <stdio.h>
#include "Gauss.h"

int main()
{
    float matrix[N][N+1] = {
        {3,6,9,39},
        {2,5,-2,3},
        {1,3,-1,2}
        };
        
    gauss(matrix);
    showMatrix(matrix);
}