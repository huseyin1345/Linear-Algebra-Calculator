#include "MatrixOperations.h"
#include "math.h"

void Operations::summation(Matrix* m1, Matrix* m2, Matrix* target){
    if(m1->rowSize == m2->rowSize && m1->columnSize == m2->columnSize){
        for(int i = 0, r = m1->rowSize; i < r; ++i){
            for(int j = 0, c = m1->columnSize; j < c; ++j){
                target->myMatrix[i][j] = m1->myMatrix[i][j] + m2->myMatrix[i][j];
            }
        }
    }else{
        std::cout<<"Error: Sizes are not equal."<<std::endl;
    }
}


void Operations::subtraction(Matrix* m1, Matrix* m2, Matrix* target){
    if(m1->rowSize == m2->rowSize && m1->columnSize == m2->columnSize){
        for(int i = 0, r = m1->rowSize; i < r; ++i){
            for(int j = 0, c = m1->columnSize; j < c; ++j){
                target->myMatrix[i][j] = m1->myMatrix[i][j] - m2->myMatrix[i][j];
            }
        }
    }else{
        std::cout<<"Error: Sizes are not equal."<<std::endl;
    }

}

void Operations::scalarMultiplication(Matrix* m, int scalar, Matrix* target){
    target->myMatrix = m->myMatrix;
    for(int i = 0, r = m->rowSize; i < r; ++i){
        for(int j = 0, c = m->columnSize; j < c; ++j){
            target->myMatrix[i][j] = m->myMatrix[i][j] * scalar;
        }
    }
    
}

void Operations::multiplication(Matrix* m1, Matrix* m2, Matrix* target){
    if(m1->columnSize == m2->rowSize){
         Matrix* temp = new Matrix(m1->columnSize, m2->rowSize);
        for(int i = 0, r = m1->rowSize; i < r; ++i){
            for(int j = 0, c = m2->columnSize; j < c; ++j){
                for(int k = 0, l=m1->columnSize; k<l; ++k){
                    temp->myMatrix[i][j] += m1->myMatrix[i][k] * m2->myMatrix[k][j];
                }
            }
        }
        
        target->rowSize = temp->rowSize;
        target->columnSize = temp->columnSize;
        target->myMatrix = temp->myMatrix;
        delete temp;
    }else{
        std::cout<<"Error: First Matrix's column size is not equal to second's row size."<<std::endl;
    }

}

void Operations::transpoze(Matrix* m, Matrix* target){
    Matrix* temp = new Matrix(m->columnSize, m->rowSize);
    for(int i = 0, r = m->rowSize; i < r; ++i){
        for(int j = 0, c = m->columnSize; j < c; ++j){
            temp->myMatrix[j][i] = m->myMatrix[i][j];
        }
    }
    target->rowSize = temp->rowSize;
    target->columnSize = temp->columnSize;
    target->myMatrix = temp->myMatrix;
    delete temp;
}

float Operations::determinant(Matrix* m) { //düzenle
    if(m->rowSize == m->columnSize){
        int size = m->rowSize;
        Matrix * temp = new Matrix(size-1, size-1);
        float det=0;
        if(size == 1){
            return m->myMatrix[0][0];
        } else if(size == 2) {
            det = m->myMatrix[0][0]*m->myMatrix[1][1]-m->myMatrix[0][1]*m->myMatrix[1][0];
        } else {
            for(int k=0, r= 0, c = 0;k<size;++k, r = c = 0) {
                for(int i=1;i<size;++i) {
                    for(int j=0;j<size;++j) {
                        if(j==k) {
                            continue;
                        }
                        temp->myMatrix[r][c] = m->myMatrix[i][j];
                        ++c;
                        if(c == size-1) {
                            ++r;
                            c = 0;
                        }
                    }
                }
                det += m->myMatrix[0][k]*pow(-1,k)*determinant(temp);
            }
        }
        delete temp;
        return det;
    }else{
        std::cout<<"Error: It's not square matrix, there is no determinant."<<std::endl;
        return NULL;
    }
}


void Operations::inverse(Matrix* m, Matrix* target){
    if(m->rowSize == m->columnSize && determinant(m) != 0){
        Matrix* temp = new Matrix(m->rowSize, m->columnSize);
        temp->myMatrix = m->myMatrix;
        temp->columnSize *= 2;
        int size = temp->rowSize;
        for(int i = 0; i<size; ++i){
            for(int j = 0; j<size; ++j){
                if(i==j) temp->myMatrix[i].push_back(1);
                else temp->myMatrix[i].push_back(0);
            }
        }
        reducedRowEchelonForm(temp, temp);
        temp->columnSize /= 2;
        
        for(int i=0; i<size; ++i){
            temp->myMatrix[i].erase(temp->myMatrix[i].begin(),temp->myMatrix[i].begin()+size);
        }
        
        
        target->myMatrix = temp->myMatrix;
        target->rowSize = temp->rowSize;
        target->columnSize = temp->columnSize;
        delete temp;
    }else{
        std::cout<<"Error: Determinant is zero or it is not square matrix"<<std::endl;
    }

}
void Operations::reducedRowEchelonForm(Matrix* m, Matrix* target){
    Matrix* tempMatrix = m;
    int lead = 0, rows = m->rowSize, cols = m->columnSize;
    for(int r = 0; r<rows; ++r){
        if(lead >= cols) break;
        int i = r;
        while (tempMatrix->myMatrix[i][lead] == 0){
            ++i;
            if(i == rows){
                i=r;
                ++lead;
                if(cols == lead)
                    break;
            }
        }
        //swap
        std::vector<double> temp = tempMatrix->myMatrix[r];
        tempMatrix->myMatrix[r] = tempMatrix->myMatrix[i];
        tempMatrix->myMatrix[i] = temp;
        //
        
        double div = tempMatrix->myMatrix[r][lead];
        if(div != 0){
            for (int j = 0; j < cols; ++j){
                tempMatrix->myMatrix[r][j] /= div;
            }
        }
        
        for(int i = 0; i<rows; ++i){
            if(i!=r){
                double sub = tempMatrix->myMatrix[i][lead];
                for (int k = 0; k < cols; k++) tempMatrix->myMatrix[i][k] -= (sub * tempMatrix->myMatrix[r][k]);
                }
            }
        
        
        ++lead;
    }
    
    target->myMatrix = tempMatrix->myMatrix;
    target->rowSize = tempMatrix->rowSize;
    target->columnSize = tempMatrix->columnSize;
    delete tempMatrix;
    
}
