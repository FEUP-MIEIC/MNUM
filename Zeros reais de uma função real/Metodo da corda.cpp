#include <iostream>
#include <iomanip>
#include <cmath>

#define PRECISON 12

using namespace std;

template <typename T>
T func_x(T x)
{
    //return x + 1 - tan(x);
    //return x*x*x*x + 2*x*x*x - x - 1;
    return x*x-4;
}

int main(int argc, char **argv)
{
    double a = atoi(argv[1]), b = atoi(argv[2]), epsilon = atof(argv[3]);
    char counter = atoi(argv[4]);

    do
    {
        double f_a = func_x(a), f_b = func_x(b), m, r;

        // calcular declive da reta que une func_x(a) e func_x(b)
        m = (f_b-f_a)/(b-a);

        // raiz da reta
        r = -f_a/m + a;

        // atualizar intervalo
        if (f_a * func_x(r) < 0) b = r;
        else a = r;

        // print
        cout << fixed << setprecision(PRECISON) << r << endl;

        counter--;
    } while(abs(a-b) > epsilon && counter > 0);
}