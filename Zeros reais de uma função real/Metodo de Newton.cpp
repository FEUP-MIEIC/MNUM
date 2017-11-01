#include <iostream>
#include <iomanip>
#include <cmath>

#define EPSILON 0.000001
#define N_ITERATIONS 10
using namespace std;

template<typename T>
T func_x(T x)
{
    return x*x*x*x + 2*x*x*x - x - 1; // f(x) = 0 => x = 
}

template<typename T>
T d_func_x(T x)
{
    return 4*x*x*x + 6*x*x - 1;
}

int main()
{
    /*
    * [a,b] é um intervalo em que f' é continua e nunca é zero
    * x0 é o guess inicial
    */
    double a = 0.367, b = 5, x0 = 4;
    unsigned int i = 0;
    while(i < N_ITERATIONS)
    {
        double xn,f_x, df_x;

        // calcular f(x0) e f'(x0)
        f_x = func_x(x0);
        df_x = d_func_x(x0);

        // calcular raiz da reta tangente a f(x) em x=x0
        xn = - f_x/df_x + x0;

        // verificar se a nova estimativa da raiz € [a,b]
        if(xn < a || xn > b)
        {
            cout << "Intervalo invalido!\n";
            break;
        }
        
        // verificar se a raiz teve uma variacao significativa
        if(abs(xn-x0) < EPSILON) break;

        // imprimir nova aproximacao da raiz
        cout << setprecision(6) << "Raiz ~ " << xn << endl;
        x0 = xn;

        // contador
        i++;
    }
}