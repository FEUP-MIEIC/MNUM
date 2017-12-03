#include <iostream>
#include <cmath>
#include <iomanip>

#define PRECISION 10
#define EPSILON 0.00001
#define N_ITERATIONS 10

template<typename T>
T func_x(T x)
{
    // f(x) = x + 1 - tan(x)
    // x = g(x) = 1 - tan(x) -> DIVERGE
    // x = g(x) = arctan(x+1) -> CONVERGE
    return atan(x+1);
}


int main()
{
    double x0 = 1, xn;
    bool goodAproximation = false;
    unsigned char counter = 0;

    do{
        xn = func_x(x0);

        std::cout << std::fixed << std::setprecision(PRECISION) << xn << std::endl;
        
        if(std::abs(xn-x0) < EPSILON) goodAproximation = true;
        else x0 = xn;

        counter ++;

    } while(counter < N_ITERATIONS && !goodAproximation);

}