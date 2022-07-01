#include <iostream>
#include <iomanip>

void printCoins(double value, int quarter, int dimes, int nickels, int pennies, int count, std::string *arr, int length);

int main(){
    double cents;
    std::cin >> cents;
    std::cout << std::fixed << std::setprecision(2) << "Amount = " << cents/100 << "\n" << std::endl;

    std::string coinArr[100];

    printCoins(cents, 0, 0, 0, 0, 1, coinArr, 0);


    return 0;
}


void printCoins(double value, int quarter, int dimes, int nickels, int pennies, int count, std::string *arr, int length){
    if(value == 0){
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
                printCoins(value - 25, quarter + 1, dimes, nickels, pennies, count + 1, arr, length + 1);
                //quarter--;
                //value -= 25;
                //break;
                //continue;
            }
            if(value - 10 > -1){
                arr[length] = "Dime";
                printCoins(value - 10, quarter, dimes + 1, nickels, pennies, count + 1, arr, length + 1);
                //dimes--;
                //value -= 10;
                //break;
                //continue;
            }
            if(value - 5 > -1){
                arr[length] = "Nickel";
                printCoins(value - 5, quarter, dimes, nickels + 1, pennies, count + 1, arr, length + 1);
                //nickels--;
                //value -= 5;
                //break;
                //continue;
            }
            if(value - 1 > -1){
                arr[length] = "Penny";
                printCoins(value - 1, quarter, dimes, nickels, pennies + 1, count + 1, arr, length + 1);
                //pennies--;
                //value -= 1;
                //break;
                //continue;
            }
            return;
        }
    }
}
