This regards the Chapter 5, about solving differential equations using numerical methods.

# First Order Diferential Equations
## Euler's Method
The Euler method is the most simple method to solve ODEs. It's also the least precise. 

Imagine you want to solve y'=y and the particular solution is known, y(0)=1. This is straightforward to solve algebrically, the solution would be y=e^x. 
![solution](/img/1.png)

We know two things. From the initial condition, we know the equation solution at x=0, which is 1 (y(0)=1). Moreover, we know the derivative of "function solution" is y (y'=y ... dy/dx=y), so we also know the slope at x=0 (y is 1 at this point, so the slope is 1 from the equation). 

These two informations allow us to build a tangent line, t0, to the solution at x=0. On this case it would be y=x+1.

Now let's assume some h, a step. For example, h=1. The next point will be x=0+h=1. We assume that the tangent line, t0, is a good aproximation to the solution till x=1. Therefore, we can build a new tangent line, t1, between the points x=1 and x=2. The initial point would be (1,2). Notice that dy/dx = y, so this new tangent line has a slope of two, hence the second point will be (2, 4). We can keep going building more tangent lines, t2, t3, t4...
x | y | dy/dx
 -- | -- | --
0 | 1 | 1
1 | 2 | 2
2 | 4 | 4
3 | 8 | 8 
![tangent line](/img/2.png)
![tangent line](/img/2_.png)

In general, for a ODE in form y' = f(x,y), we have:
* x(n+1) = x + h
* y(n+1) = yn + f(xn, yn)(x-xn)

With this successive tangent lines and with smaller steps, we can obtain better aproximations to the solution. If we want the solution at x=xn, we start from the given particular solution until we reach a tangent line that includes that particular point. Notice that the tangent line give us a solution aproximation on a range [xn, x(n+1)].