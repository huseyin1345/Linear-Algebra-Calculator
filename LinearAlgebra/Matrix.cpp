#include "Matrix.h"
#include <iomanip>

Matrix::Matrix(std::string n,int r, int c){
    name = n;
    rowSize = r;
    columnSize = c;
    myMatrix.resize(r, std::vector<double>(c, 0));
}

Matrix::Matrix(int r, int c){
    rowSize = r;
    columnSize = c;
    myMatrix.resize(r, std::vector<double>(c, 0));
}

void Matrix::assign(){
    for(int i = 0; i<rowSize; ++i){
        std::cout<<"Enter row #"<<i<<": ";
        for(int j = 0 ; j<columnSize; ++j){
            std::cin>>myMatrix[i][j];
        }
    }
}

void Matrix::printMatrix(){
    for(int i = 0; i<rowSize; ++i){
        for(int j = 0 ; j<columnSize; ++j){
            if(j==0 && i==0) std::cout<<"\u23A1";
            else if(j==0 && i == rowSize-1) std::cout<<"\u23A3";
            else if (j==0) std::cout<<"\u23A2";
            
            std::cout<<std::setw(8)<<myMatrix[i][j]<<" ";
            
            if(j==columnSize-1 && i==0) std::cout<<"\u23A4";
            else if(j==columnSize-1 && i == rowSize-1) std::cout<<"\u23A6";
            else if (j==columnSize-1) std::cout<<"\u23A5";
            
                
        }
        std::cout<<std::endl;
    }
}

