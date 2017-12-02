The chapter 4 regards quadrature rules to aproximate integrals is about calculating definite integrals.
![equation](http://latex.codecogs.com/gif.latex?%5Cint_%7Ba%7D%5E%7Bb%7Df%28x%29dx)

#Trapezium rule

The first method is the trapezium rule, which consists in aproximating the area under the curve of a function with successive trapeziums. 

For some function f(x), the integral from _x=a_ to _x=b_ consists in dividing the interval in **n** equal parts, so at each integration step the **x** increments some amplitude **h**, where **h=|(b-a)|/n**. At each step, we build a trapezium. For the first trapezium, the area is given by ![equation](http://latex.codecogs.com/gif.latex?%5Cinline%20%5Cfrac%7Bf%28a%29&plus;f%28a&plus;h%29%7D%7B2%7D*h). By summing the successive trapezium areas we can generalize the expression to 
![equation](http://latex.codecogs.com/gif.latex?%5Cint_%7Ba%7D%5E%7Bb%7Df%28x%29%3D%5Cfrac%7Bh%7D%7B2%7D%5Ccdot%20%5Bf%28a%29&plus;f%28a&plus;h%29%20&plus;%20f%28a&plus;2h%29%20&plus;%20...%20&plus;%20f%28a&plus;%28n-1%29h%29%20&plus;%20f%28b%29%5D)

##Error estimation

The trapezium rule is a second order method, therefore if **h** is reduced by half, the error is reduced aproximatelly 4 times.

If the second derivative of _f(x)_ is known, and we can determine it's maximum absolute value in the integration interval _[a,b]_, _f''(sci)_ the error is given by

![equation](http://latex.codecogs.com/gif.latex?%5Cvarepsilon%20%3D%20-%5Cfrac%7B%28b-a%29%5E%7B3%7D%7D%7B12n%5E%7B2%7D%7D%5Ccdot%20%7Bf%7D%27%27%28%5Cxi%20%29)

The error ![equation](http://latex.codecogs.com/gif.latex?%5Cinline%20%5Cvarepsilon) is upper bound, and it's just an estimation of the real error. For functions that we can't determine a good aproximation of the second derivative this doesn't apply.