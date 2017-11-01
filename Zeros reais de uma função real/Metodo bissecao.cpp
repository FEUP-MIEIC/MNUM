#include <iostream>
#include <cmath>
#include <iomanip>

#define EPSILON 0.000000001
#define OUTPUT_PRECISION 13

using namespace std;

template<typename T>
T f_x(T x)
{
    return 4-x*x;
}

int main()
{
    double a, b, f_a, f_b, f_m, m;
    bool rootFound = false;

    // set the range
    a = 0;
    b = 3;

    do
    {
        m = (a+b)/2;
        f_m = f_x(m);
        f_a = f_x(a); 
        f_b = f_x(b);
        
        if(f_m == 0) rootFound = true; // root found
        else if(f_a*f_m < 0) b=m;
        else if(f_b*f_m < 0) a=m;

        cout << setprecision(OUTPUT_PRECISION) << setfill('0')
            << "a = " << left << setw(OUTPUT_PRECISION+1) << a 
            << "\t b = " << left << setw(OUTPUT_PRECISION+1) << b << endl;

    } while (abs(a-b) > EPSILON && !rootFound);

    if(rootFound)
        cout << "Root found at x = " << m << endl;
    else
        cout << "Root on range (" << a << "," << b << ")" << endl;

}