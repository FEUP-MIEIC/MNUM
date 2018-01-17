#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return pow(x+2, 2) + (y+2,2) -5; // x=15, y=25, h=10
}

double dfx(double x, double y) {
    return 2*(x+2);
}

double dfy(double x, double y) {
    return 2*(y+2);
}

int main() {

}