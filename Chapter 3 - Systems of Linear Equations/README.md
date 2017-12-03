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

#### Internal stability 

# Iterative Methods
There are two iterative methods based on Picard-Peano method seen on Chapter 2. Iterative methods tend to diverge in most cases, so there's a convergence condition for both methods listed below. Representing a system of linear equations in matricial form, Ax=b, we need to ensure for every line in A, the element aii has an absolute value (main diagonal) higher than the sum of the remaining elements, aij, absolute value.

For example, the system below doesn't ensure the iterative methods will converge to the solution.

![example1](http://latex.codecogs.com/png.latex?\inline&space;\dpi{300}&space;\tiny&space;\begin{bmatrix}&space;3&space;&&space;5&space;&&space;100&space;&&space;10&space;&&space;118\\&space;2&space;&&space;3&space;&&space;5&space;&&space;80&space;&&space;90\\&space;200&space;&&space;4&space;&&space;6&space;&&space;5&space;&&space;215\\&space;10&space;&&space;150&space;&&space;10&space;&&space;10&space;&&space;180\\&space;\end{bmatrix})

The matrix lines would need to be re-arranged as follows.

![example](http://latex.codecogs.com/png.latex?\dpi{300}&space;\tiny&space;\begin{bmatrix}&space;200&space;&&space;4&space;&&space;6&space;&&space;5&space;&&space;215\\&space;10&space;&&space;150&space;&&space;10&space;&&space;10&space;&&space;180\\&space;3&space;&&space;5&space;&&space;100&space;&&space;10&space;&&space;118\\&space;2&space;&&space;3&space;&&space;5&space;&&space;80&space;&&space;90&space;\end{bmatrix})

An easy way to do it, is to look at the first collumn and find the line that has the largest number. That must be the first line of the matrix. The line that has the largest number on the second collumn, must be the second line of matrix, and so on.

To apply the iterative methods, just like we did on Picard-Peano, for each variable we write an equation that depends on the other variables and constant terms. For instance, for the system above, assume the variables x, y, z and w. Then we would write x in function of (y,z,w), y in function of (x,z,w) and so on.

The methods just change how x(n+1) is calculated from xn.
![equation](http://latex.codecogs.com/png.latex?\dpi{300}&space;\left\{\begin{matrix}&space;x&space;=&space;\frac&space;{215-4y-6z-5w}{200}&space;\\&space;y&space;=&space;\frac&space;{180-10x-10z-10w}{180}&space;\\&space;z&space;=&space;\frac&space;{118-3x-5y-10w}{100}&space;\\&space;w&space;=&space;\frac&space;{90-2x-3y-5z}{80}&space;\end{matrix}\right.)
## Gauss-Jacobi
![jacobi](img/jacobi.png)
## Gauss-Seidel
![seidel](img/seidel.png)   