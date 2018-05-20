#ifndef __LinearAlgebra__PredefinedMatrices__
#define __LinearAlgebra__PredefinedMatrices__

#include <iostream>
#include "Matrix.h"

/// Adding some default matrices, so user can get used to environment.
class PredefinedMatrices{
public:
    /// Container that stores the predefined matrices.
    std::vector<Matrix*> matrixContainer;
    /// Constructor of the class. It defines demo matrices.
    PredefinedMatrices();
};




#endif /* defined(__LinearAlgebra__PredefinedMatrices__) */
