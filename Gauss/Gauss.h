#ifndef GAUSS
#define GAUSS

#define N 3

void showMatrix(float matrix[N][N+1]);
void rowOp_scalar(float m[N][N+1], int l1, float coef);
void rowOp_addition(float m[N][N+1], int l1, int l2, float coef);
void gauss(float m[N][N+1]);
#endif