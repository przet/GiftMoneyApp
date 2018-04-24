#include <assert.h>
#include <iostream>
#include "item.hpp"
#include "money1.hpp"
#include <memory>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::string filename = "amounts.txt";
    double money1Amt;
    double money2Amt;
     
    std::ifstream inFile;
    std::string line;
    std::vector <std::string> lineVec;
    try 
    {
        inFile.open(filename.c_str());
        if (inFile.fail())
            throw filename;
    while (getline(inFile,line))
    {
        lineVec.push_back(line);
    }
    inFile.close();


    }
    catch(std::string e)
    {
        std::cout << "The file " << e << " was not successfully opened." << std::endl;
    }

    //Console Output Section 
    std::cout << "                          " << std::endl;
    std::cout << "                          " << std::endl;
    std::cout << "$$$$$ MONEY 1 AMOUNT $$$$$" << "          "
        << "$$$$$ MONEY 2 AMOUNT $$$$$"<<std::endl;
    std::cout << "                          " << std::endl;
    std::cout << "  ----- " <<lineVec[0]<<" -----"<<"               "
        "          "<< "-----" <<lineVec[1]<< "-----"<<std::endl;
    std::cout << "                          " << std::endl;
    std::cout << "                          " << std::endl;
    std::cout << "                          " << std::endl;

    //Money class(es) instantiation(s)
    double money1AMT = double(lineVec[0]);
    double money2AMT = double(lineVec[1]);
    Money1 money1(money1AMT);
    Money2 money2(money2AMT);
    Item item;


    //Console Input Section
    std::cout << "What would you like to do? :" <<std::endl;
    std::cout << "  1. Enter an item(s)" <<std::endl;
    std::cout << "  2. Exit" <<std::endl;
    char userInput;
    while (std::cin >> userInput)
    {
        if (userInput == '1')
        {
            std::cout << "Enter Money Spent, with a short description" << std::endl;
            L:std::cout << "Money Spent :" << std::endl;
            double itemAmount;
            std::string itemDescription;
            std::cin >> itemAmount;
            std::cout << "Description :" << std::endl;
            std::cin >> itemDescription;
            item.setPrice(itemAmount);
            item.setDescription(itemDescription);
            money1.deductItem(item);
        }
        else if (userInput == '2')
        {
            std::cout << "Exiting.....goodbye" << std::endl;
            return 0;
        }
        else
        {
            std::cerr << "Incorrect input choice, exiting, without forgiveness...goodbye" << std::endl;
            return -1;
        }
    }
    




    return 0;

}

