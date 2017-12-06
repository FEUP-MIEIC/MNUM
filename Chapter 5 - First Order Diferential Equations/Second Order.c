#include <math.h>
#include <stdio.h>

/*
 Imagine you want to solve the following second order differential equation y'' + 5y' + 6y = 0, with initial conditions y(0)=2 and y'(0)=3
 With a simple variable substituation you can solve the problem with two first order differential equations.
 For that we have three methods (Euler, RK2 and RK4)

 Let's say z = y' and
 y'' = -5y' - 6y = f(x,y,y')
 
 With the variable substituation we have the following system of two first order differential equations

 *** y' = z
 *** z' = -5z - 6y = f(x,y,z)

 And we can re-write our initial conditions as 
 *** y(0) = 2
 *** z(0) = 3

 Because both equations are first order, and we can solve them in parallel with any method (euler, RK4, RK2)
 Basically, at each iteration we have to
 *** y(n+1) = yn + yn*z
 *** z(n+1) = zn + zn*f(x,y,z)
 *** x(n+1) = xn + h
*/

//////////////////////////////////////////////
///////////// NOT SURE IF THIS IS RIGHT....
//////////////////////////////////////////////

double f(double y, double z) { // this must have three parameters if f(x,y,z) has an explicit function of x
    return -5*z - 6*y;
}

int main() {
    double x = 0, y = 2, z = 3; // initial conditions y(0) = 2 and y'(0) = z(0) = 3
    double const h = 0.1; // step

    // I am going to apply Euler's method... because I am lazy. I am going to find the solution for x=3
    
    for(int i = 0; i < 30; i++) { // number of steps is (xf-xi)/h
        double yn = y, zn = z; 
        y += h*zn;
        z += h*f(yn,zn);
        x += h;

        printf("y: %lf\n", y);
    }
}