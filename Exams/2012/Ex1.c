#include <stdio.h>

// y' = z = g(t,y,z)
double g(double t, double y, double z) {
    return z;
}

// z' = 0.5*t^2+t*z = f(t,y,z)
double f(double t, double y, double z)
{
    return 0.5 + t * t + t * z;
}

void Euler()
{
    double tn = 0, yn = 0, zn = 1, h = 0.25;
    for (unsigned int i = 0; i < 2; i++)
    {
        double y = yn, z = zn;
        yn += h * zn;
        zn += h * f(tn, yn, zn);
        tn += h;
        printf("t: %lf\ty: %lf\n", tn, yn);
    }
}

void RK4()
{
    double t = 0, y = 0, z = 1, h = 0.25;

    for (unsigned int i = 0; i < 2; i++)
    {
        double y1, y2, y3, y4,
            z1, z2, z3, z4;

        z1 = h*g(t, y, z);
        y1 = h*f(t, y, z);
        printf("z1: %lf\ty1: %lf\n", z1, y1);

        z2 = h*g(t + h/2, y + z1/2, z + y1/2);
        y2 = h*f(t + h/2, y + z1/2, z + y1/2);
        printf("z1: %lf\ty1: %lf\n", z2, y2);

        z3 = h*g(t + h/2, y + z2/2, z + y2/2);
        y3 = h*f(t + h/2, y + z2/2, z + y2/2);
        printf("z1: %lf\ty1: %lf\n", z3, y3);

        z4 = h*g(t + h, y + z3, z + y3);
        y4 = h*f(t + h, y + z3, z + y3);
        printf("z1: %lf\ty1: %lf\n", z4, y4);

        y = y + z1/6 + z2/3 + z3/3 + z4/6;
        z = z + y1/6 + y2/3 + y3/3 + y4/6;
        printf("z1: %lf\ty1: %lf\n", z1, y1);

        t += h;
        printf("\n\nt: %lf\ty: %lf\tz: %lf\n\n", t, y, z);
    }
}

int main()
{
    /*
    * Write the second order differential equation as a system of two first order differential equations
    ** y' = z
    ** z' = 0.5 + t^2 + t*z
    */

    printf("Euler\n");
    Euler();

    printf("\n\nRK4\n");
    RK4();
}
