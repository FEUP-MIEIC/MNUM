The chapter 3 regards numerical methods to solve systems of linear equations.
# Gaussian Elimination
The Gauss-Jordan method consists in transforming a matrix till the elements on the main diagonal, aii, be equal to 1, and all the remaining elements be equal to zero (identity matrix). 

1. Iterate through all matrix lines.
    * Divide all elements of the current line, **Li**, by the element of the main diagonal for that line, **aii**. If we are on the second line, we divide its elements by the element on the second row, second collumn, a22. That element, **aii**, becomes 1.
    * Next, we need to make the elements above and below **aii** equal to zero. We achieve that with subtract/addition operations over line.
        * Iterate through all the lines, **Lj**, different from **Li**. Apply **Lj = Lj - aji*Li**

A more detailed explanation can be found on [Wikipedia](https://en.wikipedia.org/wiki/Gaussian_elimination).