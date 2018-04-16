#include <assert.h>
#include <iostream>
#include "item.hpp"
#include "money1.hpp"
#include <memory>

int main()
{
    const double money1Amt = 100;
    const double money2Amt = 200;
    
    //Program User Interaction Section
    std::cout << "Please select (1,2,...) choice: " << std::endl;
    std::cout << "1. Show amount in both monies " << std::endl;
    char input;
    std::cin >> input;
    if (input = '1')
        std::cout << "hello";

    Item item;
    Money1 money1(money1Amt);
    Money1 *money1_ptr = &money1;
    item.setPrice(120);
    money1.deductItem(item);
    if (money1.getAmount() <= 0)
    { 
        std::cout << "out of money:switching over to 2" << std::endl;
    }  
   
    
        Money2 money2 (money2Amt -money1.getAmount(), money1_ptr);
    if (money2.getAmount() <= 0)
        std::cout << "out of money!" << std::endl;
  
    

    







    return 0;

}
