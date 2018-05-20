#ifndef __LinearAlgebra__Application__
#define __LinearAlgebra__Application__

#include <iostream>
#include "Matrix.h"
#include "MatrixOperations.h"
#include "PredefinedMatrices.h"

/// Command Line Interface of the program.
class Application{
    
    /// Container that holds content of all matrices.
    std::vector<Matrix*> matrixContainer;
    
public:
    /// Constructor of the class. Imports predefined matrices.
    Application();
    
    /// Runs command panel of the program.
    void run();
    
    /** It takes a string as argument n and traverses the matrixContainer for looking if there is a Matrix with named n.
     * If there is, returns false, otherwise true.
     */
    bool searchName(std::string n);
    
    /// Traverses the matrixContainer and returns the index of matrix named "std::string n" 
    int findIndex(std::string n);
};
#endif /* defined(__LinearAlgebra__Application__) */
