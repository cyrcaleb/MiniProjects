#include <iostream>
#include <cmath>
#include <vector>


void fibVec(long int *ptr1, long int *ptr2, int rows, int cols, int number, int &counter);  //function to get matrices from user
void addM(long int *ma1, long int *ma2, int *ma3, int rows, int cols);                      //function to add matrices together 
void printM(int currentM, int rows, int cols, long int *value, int totalM);                 //function to print a matrix


int main(){
    int length, width, num, count = 1;
    
    std::cout << "Enter number of matrices \n";
    std::cin >> num;
    std::cout << "\n";
    
    std::cout << "Enter length and width for matrices \n";
    std::cin >> length >> width;
    std::cout << "\n";
    
    //initializes two matricies
    long int m1[length * width];  //holds values of the sum of all matrices when it gets rewritten each time
    long int m2[length * width];  //hold values of current matrix when user inputs it so it can be printed

    fibVec(m1, m2, length, width, num, count);      //calls function to get matricies
    printM(count, length, width, m1, num);          //call function to print Sum Matrix
    
    return 0;
}



void addM(long int *ma1, long int *ma2, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){      //rewrites over each index of matrix 1 by adding the two matrix inputs together
            *ma1 = (*ma1) + (*ma2);     
            ma1++;
            ma2++;
        }
    }
}



void fibVec(long int *ptr1, long int *ptr2, int rows, int cols, int number, int &counter){
    long int *addhold1 = ptr1, *addhold2 = ptr2;   //stores initial memory location of the two arrays
    bool isDone = false;
    long int *holdp1 = ptr1;  //holds the location for which matrix will get its values written over (m1 or m2)
    
    
    while(isDone == false){
        std::cout << "Type " << rows * cols << " numbers for Matrix " << counter << std::endl;
        
        if(counter == 1){                           //puts user input values into matrix one
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    std::cin >> *ptr1;
                    ptr1++;
                }
            }
            std::cout << "\n";
            
        }
        else{                                      //puts user input values into matrix two
            holdp1 = addhold2;                     //resets value for which matrix to print (line 78) 
            ptr2 = addhold2;                       //resets memory location to first index of the m2 array
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    std::cin >> *ptr2;
                    ptr2++;
                }
            }
            std::cout << "\n";
        }
        
        printM(counter, rows, cols, holdp1, number);    //calls function to print out current matrix
        
        if(counter > 1){                                //calls function to add matricies together
            addM(addhold1, addhold2, rows, cols);       
        }
        
        if(counter == number){
            isDone = true;
        }
        counter++;
    
    }
}



void printM(int currentM, int rows, int cols, long int *value, int totalM){
    if(currentM > totalM){ 
        std::cout << "Matrix Sum: \n";
    }
    else{
        std::cout << "Matrix " << currentM << ": \n";
    }
    
    for(int i = 0; i < rows; i++){                      //Uses different spacing so values line up correctly
        for(int j = 0; j < cols; j++){
            if(*value >= 100000){
                std::cout << " " << *value << " ";
            }
            else if(*value >= 10000){
                std::cout << "  " << *value << " ";
            }
            else if(*value >= 1000){
                std::cout << "   " << *value << " ";
            }
            else if(*value >= 100){
                std::cout << "    " << *value << " ";
            }
            else if(*value >= 10){
                std::cout << "     " << *value << " ";
            }else{
                std::cout << "      " << *value << " ";
            }
            value++;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}