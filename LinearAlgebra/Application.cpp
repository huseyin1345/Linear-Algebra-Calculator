#include "Application.h"



Application::Application(){
    PredefinedMatrices* pdm = new PredefinedMatrices();
    matrixContainer = pdm->matrixContainer;
    std::cout<<"===Linear Algebra Calculator==="<<std::endl
    <<"Huseyin Bulut - 20130602006"<<std::endl
    <<"Type help for see commands."<<std::endl;
}

bool Application::searchName(std::string n){
    for(int i = 0; i<matrixContainer.size(); ++i){
        if(matrixContainer[i]->name == n){
            return false;
        }
    }
    return true;
}
int Application::findIndex(std::string n){
    for(int i = 0; i<matrixContainer.size(); ++i)
        if (matrixContainer[i]->name == n) return i;
    return NULL;
}
void Application::run(){
    
    Operations* op = new Operations();
    
    std::string matrixName,command;
    int r,c;
    
    while (1) {
        std::cout<<">";
        std::cin>>command;
        if(command == "def"){
            
            std::cin>>matrixName;
            std::cin>>r>>c;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,r,c));
                matrixContainer[matrixContainer.size()-1]->assign();
            }
            else
                std::cout<<"Error: There is another matrix with same name."<<std::endl;
            
        }else if(command == "print"){
            std::cin>>matrixName;
            if (!searchName(matrixName)) {
               matrixContainer[findIndex(matrixName)]->printMatrix();
            }else{
                std::cout<<"Error: There is not a matrix called :"<<matrixName<<std::endl;
            }
        }else if(command == "del"){
            std::cin>>matrixName;
            
            matrixContainer.erase(matrixContainer.begin()+findIndex(matrixName));
        }else if(command == "sum"){
            int temp1, temp2, temp3;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            std::cin>>matrixName;
            temp2 = findIndex(matrixName);
            
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp3 = findIndex(matrixName);
            op->summation(matrixContainer[temp1], matrixContainer[temp2], matrixContainer[temp3]);
        }else if(command == "sub"){
            int temp1, temp2, temp3;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            std::cin>>matrixName;
            temp2 = findIndex(matrixName);
            
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp3 = findIndex(matrixName);
            op->summation(matrixContainer[temp1], matrixContainer[temp2], matrixContainer[temp3]);
        }else if (command == "mul"){
            int temp1, temp2, temp3;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            std::cin>>matrixName;
            temp2 = findIndex(matrixName);
            
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp3 = findIndex(matrixName);
            op->multiplication(matrixContainer[temp1], matrixContainer[temp2], matrixContainer[temp3]);
        }else if (command == "tps"){
            int temp1, temp2;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp2 = findIndex(matrixName);
            op->transpoze(matrixContainer[temp1], matrixContainer[temp2]);
        }else if (command == "smul"){
            int temp1, temp2, scalar;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            std::cin>>scalar;
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp2 = findIndex(matrixName);
            op->scalarMultiplication(matrixContainer[temp1],scalar, matrixContainer[temp2]);
        }else if (command == "inv"){
            int temp1, temp2;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp2 = findIndex(matrixName);
            op->inverse(matrixContainer[temp1], matrixContainer[temp2]);
        }else if (command == "rrew"){
            int temp1, temp2;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            
            std::cin>>matrixName;
            if(searchName(matrixName)){
                matrixContainer.push_back(new Matrix(matrixName,matrixContainer[temp1]->rowSize,matrixContainer[temp1]->columnSize));
            }
            temp2 = findIndex(matrixName);
            op->reducedRowEchelonForm(matrixContainer[temp1], matrixContainer[temp2]);
        }else if (command == "det"){
            int temp1;
            std::cin>>matrixName;
            temp1 = findIndex(matrixName);
            std::cout<<"Determinant is: "<<op->determinant(matrixContainer[temp1])<<std::endl;
        }else if (command == "exit"){
            break;
        }else if (command == "show"){
            for(int i = 0; i<matrixContainer.size(); ++i){
                std::cout<<matrixContainer[i]->name<<" ("<<matrixContainer[i]->rowSize<<"x"<<matrixContainer[i]->columnSize<<")"<<std::endl;
            }
        }else if (command == "help"){
            std::cout<<"Commands list:"<<std::endl
            << "show : prints all matrices' names and size."<<std::endl
            << "print + [MATRIXNAME] : prints contents of the matrix."<<std::endl
            << "del + [MATRIXNAME] : deletes the matrix."<<std::endl
            << "def + [MATRIXNAME] + [ROWSIZE] + [COLUMNSIZE] : defines a new matrix."<<std::endl
            << "sum + [MATRIX1] + [MATRIX2] + [TARGET] : Adds Matrix1 and Matrix2, and assigns to Target ."<<std::endl
            << "sub + [MATRIX1] + [MATRIX2] + [TARGET] : Subtracts Matrix1 by Matrix2, and assigns to Target ."<<std::endl
            << "mul + [MATRIX1] + [MATRIX2] + [TARGET] : Multiplies Matrix1 and Matrix2, and assigns to Target ."<<std::endl
            << "smul + [MATRIX] + number + [TARGET] : Multiplies all elements of Matrix with number."<<std::endl
            << "tps + [MATRIX1] + [TARGET] : Finds transpoze Matrix1 and assigns to Target."<<std::endl
            << "rrew + [MATRIX1] + [TARGET] : Finds Reduced Row Echelon Form of Matrix1 and assigns to Target."<<std::endl
            << "inv + [MATRIX1] + [TARGET] : Finds inverse of Matrix1 and assigns to Target."<<std::endl
            << "det + [MATRIX1]: Finds determinant of Matrix1 and prints."<<std::endl
            << "exit: Exit program.\n\n\n"
            <<"For example, if you want to add Matrix A and B, type :"<<std::endl
            <<"sum A B A"<<std::endl
            <<"If you don't want to lose content, then you can type:"<<std::endl
            <<"sum A B C"<<std::endl
            <<"If there is not a matrix named C, program will create automatically."<<std::endl;
            
        }else{
            std::cout<<"There is no command as "<<command<<", try again."<<std::endl;
        }
        
        
    } //end while
    delete op;
}