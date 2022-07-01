//Donavan Francis and Caleb Cyr
//cyrcaleb - Github
//dfrancis07 - Github

#include <iostream>
#include <iomanip>

//This is a program that asked for a value of money as a decimal and lets the user know all the possible permutaions to get
//the value using coins

void printCoins(double value, int dollars_hundred, int dollars_fifty, int dollars_twenty, int dollars_ten, int dollars_five, int dollar, int quarter, int dimes, int nickels, int pennies);

int main(){
    double cents;
    
    std::cout << "Input your dollar amoount without the decimal. EX: for ($24.63) enter (2463)" << std::endl;

    std::cin >> cents;
    std::cout << std::fixed << std::setprecision(2) << cents/100 << std::endl;
    

    printCoins(cents, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


    return 0;
}


void printCoins(double value, int dollars_hundred, int dollars_fifty, int dollars_twenty, int dollars_ten, int dollars_five, int dollar, int quarter, int dimes, int nickels, int pennies){
    if(value == 0){
        std::cout << "$100 Dollars: " << dollars_hundred << std::endl;
        std::cout << "$50 Dollars: " << dollars_fifty << std::endl;
        std::cout << "$20 Dollars: " << dollars_twenty << std::endl;
        std::cout << "$10 Dollars: " << dollars_ten << std::endl;
        std::cout << "$5 Dollars: " << dollars_five << std::endl;
        std::cout << "Dollars: " << dollar << std::endl;
        std::cout << "Quarters: " << quarter << std::endl;
        std::cout << "Dimes: " << dimes << std::endl;
        std::cout << "Nickels: " << nickels << std::endl;
        std::cout << "Pennies: " << pennies << std::endl;
        std::cout << std::endl;
        return;
    }
    else{
        bool run = true;
        while (run){
            if(value - 10000 > 0){
                printCoins(value - 10000, dollars_hundred + 1, dollars_fifty, dollars_twenty, dollars_ten, dollars_five, dollar, quarter, dimes, nickels, pennies);
                //nickels--;
                //value -= 5;
                //std::cout << value << std::endl;
                break;
                //continue;
            }
            if(value - 5000 > 0){
                printCoins(value - 5000, dollars_hundred, dollars_fifty + 1, dollars_twenty, dollars_ten, dollars_five, dollar, quarter, dimes, nickels, pennies);
                //pennies--;
                //value -= 1;
                //std::cout << value << std::endl;
                break;
                //continue;
            }
            if(value - 2000 > 0){
                printCoins(value - 2000, dollars_hundred, dollars_fifty, dollars_twenty + 1, dollars_ten, dollars_five, dollar, quarter, dimes, nickels, pennies);
                //quarter--;
                //value -= 25;
                //std::cout << value << std::endl;
                break;
                //continue;
            }
            if(value - 1000 > 0){
                printCoins(value - 1000, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten + 1, dollars_five, dollar, quarter, dimes, nickels, pennies);
                //dimes--;
                //value -= 10;
                //std::cout << value << std::endl;
                break;
                //continue;
            }
            if(value - 500 > 0){
                printCoins(value - 500, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten, dollars_five + 1, dollar, quarter, dimes, nickels, pennies);
                //nickels--;
                //value -= 5;
                //std::cout << value << std::endl;
                break;
                //continue;
            }
            if(value - 100 > 0){
                printCoins(value - 100, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten, dollars_five, dollar + 1, quarter, dimes, nickels, pennies);
                //pennies--;
                //value -= 1;
                //std::cout << value << std::endl;
                break;
                //continue;
            }
            if(value - 25 > -1){
                printCoins(value - 25, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten, dollars_five, dollar, quarter + 1, dimes, nickels, pennies);
                //quarter--;
                //value -= 25;
                break;
                //continue;
            }
            if(value - 10 > -1){
                printCoins(value - 10, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten, dollars_five, dollar, quarter, dimes + 1, nickels, pennies);
                //dimes--;
                //value -= 10;
                break;
                //continue;
            }
            if(value - 5 > -1){
                printCoins(value - 5, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten, dollars_five, dollar, quarter, dimes, nickels + 1, pennies);
                //nickels--;
                //value -= 5;
                break;
                //continue;
            }
            if(value - 1 > -1){
                printCoins(value - 1, dollars_hundred, dollars_fifty, dollars_twenty, dollars_ten, dollars_five, dollar, quarter, dimes, nickels, pennies + 1);
                //pennies--;
                //value -= 1;
                break;
                //continue;
            }
        }
    }
}
