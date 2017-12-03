The chapter 3 regards numerical methods to solve systems of linear equations.
# Gaussian Elimination
The Gauss-Jordan method consists in transforming a matrix till the elements on the main diagonal, aii, be equal to 1, and all the remaining elements be equal to zero (identity matrix). 

* Iterate through all matrix lines.
    * Divide all elements of the current line, **Li**, by the element of the main diagonal for that line, **aii**. If we are on the second line, we divide its elements by the element on the second row, second collumn, a22. That element, **aii**, becomes 1.
    * Next, we need to make the elements above and below **aii** equal to zero. We achieve that with subtract/addition operations over line.
        * Iterate through all the lines, **Lj**, different from **Li**. Apply **Lj = Lj - aji*Li**

A more detailed explanation can be found on [Wikipedia](https://en.wikipedia.org/wiki/Gaussian_elimination).

[Implementation in C language](Gaussian%20elimination.c)

## Error
### Internal and external stability
There are two types of erros in Gauss method. 
* Internal stability : This is due calculation process, such rounding and truncation.
* External stability : erros in the data such coeficients and independent terms.

#### External stability
Consider the system of linear equations represented in matrix form, Ax=b, with N equations, so A has NxN dimensions, x has Nx1 dimensions and b has Nx1 dimmesions. 
If we know that matrix A (containg the terms coeficients) has some error ![deltaA](http://latex.codecogs.com/png.latex?\inline&space;\dpi{150}&space;\tiny&space;\delta&space;a) and matrix b has some error ![deltaB](http://latex.codecogs.com/png.latex?\inline&space;\dpi{150}&space;\tiny&space;\delta&space;b), we are interested in determine the error ![deltaX](http://latex.codecogs.com/png.latex?\inline&space;\dpi{150}&space;\tiny&space;\delta&space;x), which is the error that affects the solution of the system.

![formula](http://latex.codecogs.com/png.latex?\inline&space;\dpi{300}&space;\tiny&space;A.\delta&space;x&space;=&space;\delta&space;b&space;\pm&space;\delta&space;A.X_{0})

Solving the above system shows how the solutions are affected. 
![deltaA](http://latex.codecogs.com/png.latex?\inline&space;\dpi{150}&space;\tiny&space;\delta&space;a) is a NxN matrix, filled with the error that affects A and ![deltaB](http://latex.codecogs.com/png.latex?\inline&space;\dpi{150}&space;\tiny&space;\delta&space;b) is a Nx1 matrix filled with the error that affects B.
![deltaX](http://latex.codecogs.com/png.latex?\inline&space;\dpi{150}&space;\tiny&space;X_{0}) represents the system solution.
