#include <iostream>
#include <cmath>
#include <iomanip>

#define EPSILON 0.000001
#define PRECISION 10
#define N_ITERATIONS 15

using namespace std;

template<typename T>
T func_x(T x)
{
    return 4-x*x;
}

int main(int argc, char **argv)
{
    double a = atoi(argv[1]), b = atoi(argv[2]);
    unsigned char counter = 0;

    do
    {
        double f_a = func_x(a), f_b = func_x(b), 
            f_m, m;

        if(f_a*f_b > 0)
        {
            cout << "Intervalo inválido!\n";
            break;
        }

        m = (a+b)/2;
        f_m = func_x(m);

        if(f_a*f_m < 0) b = m;
        else a = m;

        cout << fixed << setprecision(PRECISION) << m << endl;

        counter++;

    } while(abs(a-b) > EPSILON && counter < N_ITERATIONS);
}