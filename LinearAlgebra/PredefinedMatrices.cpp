#include "PredefinedMatrices.h"
#include "stdlib.h"
#include "time.h"

PredefinedMatrices::PredefinedMatrices(){
    srand(time(NULL));
    
    matrixContainer.push_back(new Matrix("random",3,3));
    matrixContainer.push_back(new Matrix("test1",5,5));
    matrixContainer.push_back(new Matrix("test2",5,5));
    matrixContainer.push_back(new Matrix("empty",5,5));
    matrixContainer.push_back(new Matrix("notsquare",5,10));
    matrixContainer.push_back(new Matrix("randnotsquare",5,10));
    
    for(int i = 0; i<3; ++i){
        for(int j = 0 ; j<3; ++j){
            matrixContainer[0]->myMatrix[i][j] = rand()%100;
        }
    }
    
    for(int i = 0; i<5; ++i){
        for(int j = 0 ; j<5; ++j){
            matrixContainer[1]->myMatrix[i][j] = i+j;
        }
    }
    for(int i = 0; i<5; ++i){
        for(int j = 0 ; j<5; ++j){
            matrixContainer[2]->myMatrix[i][j] = j*j+i*i;
        }
    }
    for(int i = 0; i<5; ++i){
        for(int j = 0 ; j<10; ++j){
            matrixContainer[4]->myMatrix[i][j] = i+j;
        }
    }
    for(int i = 0; i<5; ++i){
        for(int j = 0 ; j<10; ++j){
            matrixContainer[4]->myMatrix[i][j] = rand()%100;
        }
    }
}