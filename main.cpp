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
    Money1 money1(double(lineVec[0]));
    Money2 money2(double(lineVec[1]));
    Item item;


    //Console Input Section
    std::cout << "Enter Money Spent, with a short description" << std::endl;
    std::cout << "Money Spent :" << std::endl;
    double itemAmount;
    std::string itemDescription;
    std::cin >> itemAmount;
    std::cout << "Description :" << std::endl;
    std::cin >> itemDescription;
    item.setPrice(itemAmount);
    item.setDescription(itemDescription);
    
     

     
    

    







    return 0;

}
