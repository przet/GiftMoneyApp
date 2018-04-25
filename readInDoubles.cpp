#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::string filename = "amounts.txt";
    std::fstream amountsFile(filename, std::ios::in);
    if(amountsFile.fail())
    {
        std::cerr <<"\nError!!\nThe file " <<filename 
        << " could not be openend.\nDoes it exist?\n"
        "Perhaps it is being used by another program?\n"
        "Exiting....\n"<< std::endl;
        return -1;
    }//TODO...std::cerr and return -1...read more about them

    //The text file has two numbers, seperated by a new line. Read in the numbers into
    //two double variables
    
    double number1, number2;
    amountsFile >> number1 >> number2;
    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
   
    return 0;
}



