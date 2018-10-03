The chapter 4 regards quadrature rules to aproximate integrals such definite integrals.
![equation](http://latex.codecogs.com/gif.latex?%5Cint_%7Ba%7D%5E%7Bb%7Df%28x%29dx)

# Trapezium rule

The first method is the trapezium rule, which consists in aproximating the area under the curve of a function with successive trapeziums. 

For some function f(x), the integral from _x=a_ to _x=b_ consists in dividing the interval in **n** equal parts, so at each integration step the **x** increments some amplitude **h**, where **h=|(b-a)|/n**. 

At each step, we build a trapezium. For the first trapezium, the area is given by ![equation](http://latex.codecogs.com/gif.latex?%5Cinline%20%5Cfrac%7Bf%28a%29&plus;f%28a&plus;h%29%7D%7B2%7D*h).

By summing the successive trapezium areas we can generalize the expression to 
![equation](http://latex.codecogs.com/gif.latex?%5Cint_%7Ba%7D%5E%7Bb%7Df%28x%29%3D%5Cfrac%7Bh%7D%7B2%7D%5Ccdot%20%5Bf%28a%29&plus;2f%28a&plus;h%29%20&plus;%202f%28a&plus;2h%29%20&plus;%20...%20&plus;%202f%28a&plus;%28n-1%29h%29%20&plus;%20f%28b%29%29%5D)

## Error estimation

The trapezium rule is a second order method, therefore if **h** is reduced by half, the error is reduced aproximatelly 4 times.

If the second derivative of _f(x)_ is known, and we can determine it's maximum absolute value in the integration interval _[a,b]_, _f''(sci)_, the error is given by

![equation](http://latex.codecogs.com/gif.latex?%5Cvarepsilon%20%3D%20-%5Cfrac%7B%28b-a%29%5E%7B3%7D%7D%7B12n%5E%7B2%7D%7D%5Ccdot%20%7Bf%7D%27%27%28%5Cxi%20%29)

The resultant error ![equation](http://latex.codecogs.com/gif.latex?%5Cinline%20%5Cvarepsilon) is upper bound, and it's just an estimation of the real error. For functions that we can't determine a good aproximation of the second derivative this doesn't apply.

# Simpson rule

The simpson rule aproximates the area under the curve of a function f(x) with parabolas (union of three function points). This is an improvement over the trapezium rule. If the sign of the second derivative of f doesn't change, the trapezium rule drives to a sistematic error. With parabolas, the aproximation precision increases. 

To integrate a function f(x) between **a** and **b**, with **n** (even) steps, the general formula is

![equation](http://latex.codecogs.com/gif.latex?I%20%3D%20%5Cfrac%7Bh%7D%7B3%7D%5Bf%28a%29%20&plus;%204f%28a&plus;h%29%20&plus;%202f%28a&plus;2h%29%20&plus;%20...%20&plus;%204f%28a&plus;%28n-2%29h%29%20&plus;%202f%28a&plus;%28n-1%29h%29&plus;f%28b%29%5D)

## Error estimation

Just like with the trapezium rule, it's possible to estimate the error. The simpson rule is a 4th order method. That means that if **h** is reduced by half, the error should be reduced aproximatelly 16 times.

![equation](http://latex.codecogs.com/gif.latex?%5Cvarepsilon%20%3D%20-%20%5Cfrac%7B%7B%28b-a%29%7D%5E5%7D%7B90%7Bn%7D%5E4%7D%7Bf%7D%27%27%27%27%28%5Cxi%20%29)


# Convergence coefficient
When it's not possible to estimate errors with the above formulas, an alternative is the convergence coefficient, that allows to control the error. 

The idea is to calculate the integrals _I_, _I'_ and _I''_, where
* _I_ uses an amplitude _h_
* _I'_ uses _h'=h/2_ 
* _I''_ is calculated with _h''_ = _h/4_.

Next, we evaluate the following ratio. If it's aproximately 2^n, then _I''_ is good aproximattion of the exact integral value. **n** is the order of the method. The trapezium rule is a second order method, so the ratio should be aproximatelly 4, and the simpson rule is a fourth order method, so the ratio should be aproximatelly 16.

![equation](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%7BI%7D%27-I%7D%7B%7BI%7D%27%27-%7BI%7D%27%7D%5Capprox%20%7B2%7D%5En)

And the error for _I''_, the best integral aproximation, is evaluated as

![equation](http://latex.codecogs.com/gif.latex?%7B%5Cvarepsilon%7D%27%27%20%3D%20%5Cfrac%20%7B%7BI%7D%27%27-%7BI%7D%27%7D%7B%7B2%7D%5En-1%7D)
