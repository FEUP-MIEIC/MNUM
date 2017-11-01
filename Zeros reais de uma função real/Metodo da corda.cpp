#include <iostream>
#include <iomanip>
#include <cmath>

#define PRECISON 5
#define EPSILON 0.000005
using namespace std;

template <typename T>
T func_x(T x)
{
    //return x + 1 - tan(x);
    return x*x*x*x + 2*x*x*x - x - 1;
}

int main()
{
    float a, b, f_a, f_b, r, f_r;
    bool rootFound = false;

    // set interval
    a = 0;
    b = 1;

    do
    {
        // print the current interval
        cout << setprecision(PRECISON)
            << "a = " << left << setw(PRECISON+1) << a 
            << "\t b = " << left << setw(PRECISON+1) << b << endl;

        f_a = func_x(a);
        f_b = func_x(b);

        // check if f_a * f_b < 0 (otherwise this interval is invalid) and if root was found
        if (f_a * f_b > 0)
        {
            std::cout << "Intervalo inválido!!";
            return -1;
        }
        else if (f_a == 0 || f_b == 0)  rootFound = true;

        // calculate the root of the line that intersects f_a and f_b
        r = a - f_a * (b-a) / (f_b - f_a);

        // calculate f(r)
        f_r = func_x(r);

        // check if the new root is similar to the previous one. If not, sets a new interval
        if(f_r *  f_a < 0) 
        {
            if(abs(b-r) < EPSILON) break;
            b = r;
        }
        else
        {
            if(abs(a-r) < EPSILON) break;
            a = r;
        } 

    } while (!rootFound);

    if(f_a == 0) cout << "Root found at x=" << a;
    else if (f_b == 0) cout << "Root found at x=" << b;
    else cout << "Root x ~ " << r;
}