#ifndef __LinearAlgebra__Matrix__
#define __LinearAlgebra__Matrix__

#include <iostream>
#include <vector>
/// It holds the content of a matrix.
class Matrix{
public:
    /// A vector of vector that represents a matrix.
    std::vector<std::vector<double> > myMatrix;
    /// Name of the matrix
    std::string name;
    /// Row Size of the matrix
    int rowSize;
    /// Column Size of the matrix
    int columnSize;
    
    /** Constructor of the matrix. I takes three arguments:
     * Name, Row Size and Column Size
     * Creates a matrix with those arguments.
     */
    Matrix(std::string n,int r, int c);
    /// Another constructor. It creates a matrix with no name. It is using only for creating temporary matrices.
    Matrix(int r, int c);
    /// It takes the content of the matrix from user.
    void assign();
    
    /// Prints the matrix to the screen.
    void printMatrix();
    
};

#endif /* defined(__LinearAlgebra__Matrix__) */
