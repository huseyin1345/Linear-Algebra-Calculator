#ifndef __LinearAlgebra__MatrixOperations__
#define __LinearAlgebra__MatrixOperations__

#include <iostream>
#include "Matrix.h"

///Contains Matrix Operations
class Operations{
public:
/** Summation of two matrices.
 *  It takes three arguments: Matrix1, Matrix2, and TargetMatrix
 *  Adds contents of Matrix1 and Matrix2. Then writes the result on TargetMatrix. */
void summation(Matrix* m1, Matrix* m2, Matrix* target);

/** Subtraction of two matrices.
 *  It takes three arguments: Matrix1, Matrix2, and TargetMatrix
 *  Subtracts contents of Matrix1 and Matrix2. Then writes the result on TargetMatrix. */
void subtraction(Matrix* m1, Matrix* m2, Matrix* target);

/** Multiplication of two matrices.
 *  It takes three arguments: Matrix1, Matrix2, and TargetMatrix
 *  Dot-Products the contents of Matrix1 and Matrix2. Then writes the result on TargetMatrix. */
void multiplication(Matrix* m1, Matrix* m2, Matrix* target);

/** Transpose Operation.
 *  It takes three arguments: Matrix1 and TargetMatrix
 *  Converts Matrix1[i][j] to Matrix1[j][i] and writes the result on TargetMatrix. */
void transpoze(Matrix* m, Matrix* target);

/** Finds determinant.
 *  It takes one argument: a Matrix
 *  Calculates the determinant and returns the result. */
float determinant(Matrix* m);

/** Matrix Inversion Operation.
 *  It takes three arguments: Matrix1 and TargetMatrix
 *  Adds an Identity matrix at the end of Matrix1. It turns M[A|I], then calls reducedRowEchelonForm().
 *  After that Matrix become M[I^-1|A]. Writes second half of the matrix on target. */
void inverse(Matrix* m, Matrix* target);

/** Reduced Row Echelon Form converter.
 *  It takes two argument: a Matrix and a target matrix.
 *  Reduces the matrix, so variables' values can found. */
void reducedRowEchelonForm(Matrix* m, Matrix* target);

/** Scalar Multiplication.
 *  It takes three arguments: a Matrix, a scalar value and target.
 *  Multiplies all values of the matrix by scalar value and writes it on target Matrix */
void scalarMultiplication(Matrix* m, int scalar, Matrix* target);
    
};
#endif /* defined(__LinearAlgebra__MatrixOperations__) */
