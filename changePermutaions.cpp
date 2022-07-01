#include <iostream>
#include <iomanip>
//This is a program that asked for a value of money as a decimal and lets the user know all the possible permutaions to get
//the value using coins

void printCoins(double value, int quarter, int dimes, int nickels, int pennies, int count, std::string *arr, int length, int *total);

int main(){
    double cents;
    int perms = 0;
    std::cin >> cents;
    std::cout << std::endl;
    
    std::cout << std::fixed << std::setprecision(2) << "Amount = " << cents/100 << "\n" << std::endl;

    std::string coinArr[100];

    printCoins(cents, 0, 0, 0, 0, 1, coinArr, 0, &perms);
    
    std::cout << "Total Permutations = " << perms << std::endl;
    

    return 0;
}


void printCoins(double value, int quarter, int dimes, int nickels, int pennies, int count, std::string *arr, int length, int *total){
    if(value == 0){
        *total+=1;
        for(int i = 1; i <= length; i++){
            std::cout << "Coin " << i << " = " << arr[i-1] << std::endl;
        }
        std::cout << std::endl;
        length = 0;
        std::cout << "Quarters: " << quarter << std::endl;
        std::cout << "Dimes: " << dimes << std::endl;
        std::cout << "Nickels: " << nickels << std::endl;
        std::cout << "Pennies: " << pennies << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << std::endl;
    }
    else{
        bool run = true;
        while (run){
            if(value - 25 > -1){
                arr[length] = "Quarter";
                printCoins(value - 25, quarter + 1, dimes, nickels, pennies, count + 1, arr, length + 1, total);
                //quarter--;
                //value -= 25;
                //break;
                //continue;
            }
            if(value - 10 > -1){
                arr[length] = "Dime";
                printCoins(value - 10, quarter, dimes + 1, nickels, pennies, count + 1, arr, length + 1, total);
                //dimes--;
                //value -= 10;
                //break;
                //continue;
            }
            if(value - 5 > -1){
                arr[length] = "Nickel";
                printCoins(value - 5, quarter, dimes, nickels + 1, pennies, count + 1, arr, length + 1, total);
                //nickels--;
                //value -= 5;
                //break;
                //continue;
            }
            if(value - 1 > -1){
                arr[length] = "Penny";
                printCoins(value - 1, quarter, dimes, nickels, pennies + 1, count + 1, arr, length + 1, total);
                //pennies--;
                //value -= 1;
                //break;
                //continue;
            }
            return;
        }
    }
}
