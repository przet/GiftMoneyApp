#include <assert.h>
#include <iostream>
#include "item.hpp"
#include "money1.hpp"
int main()
{
    //Assumptions:
    //  -Money1 has $100, Money2 has $200.
    //  -Money1 is the first Money amount we will draw from        
    
    //Test0: Testing assert.h: first time I am using it
    int i = 1;
    int j = 3;
    //assert(j==i); O.K. Works. A bit messy though, causes program termination...
    //don't know if there are any issues with this..

    //Test1: I spent $20 on an item.
    Item item;
    Money1 money1(100);
    item.setPrice(20);
    money1.deductItem(item);
    assert(money1.getAmount() == 80);

    //Test2: Money1 has now $80. I spend $100.
    //I need money1.getAmount to switch over into money2

    Item item2;
    item2.setPrice(100);
    money1.deductItem(Item);
    // I will stop testing via here and enter the main app...
    // The lack of framework may make it harder to test in this fashion.
    // I want to actually test program logic (like create Money 2 if Money1<0 etc)
    // and really what I am doing here in this file is almost the logic! But it has created the initial
    // design :)














    return 0;

};
