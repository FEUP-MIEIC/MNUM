#include <stdio.h>
#define N 4

// calculates the residum for some variable xi (b-A*x0)
// because A and x0 are vectors, this function requires the ith row from A
double aux(double b, double A[N], double x0[N]) {
    double e = 0;

    for(int i = 0; i < N; i++) {
        e += A[i]*x0[i];
    }

    return b - e;
}
int main() {
    // epsilon = b - A*x0

    double b[N] = {1.0,0.0,1.0,0.0};
    double A[N][N] = {
        {0.25000,0.33333,0.50000,1.00000},
        {0.20000,0.25000,0.33333,0.50000},
        {0.16667,0.20000,0.25000,0.33333},
        {0.14286,0.16667,0.20000,0.25000}
    };
    double x0[N] = {-4360.05196,6754.68422,-2837.21000,258.07910};


    for(int i = 0; i < N; i++) {
        printf("x%d: %lf\n", i+1, aux(b[i], A[i], x0));
    }
}
