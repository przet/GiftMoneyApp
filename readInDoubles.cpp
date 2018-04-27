#include <fstream>
#include <string>
#include <iostream>

//B: stands for "behaviour"

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

    //
    //B:The text file has two numbers, seperated by a new line. Read in the numbers into
    //two double variables
    //
    
    double number1, number2;
    amountsFile >> number1 >> number2;
    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
    amountsFile.close();
    

    //
    //B:Read in a double value and change first line in the file to that value. Include checks that it
    //has actually been done.
    //
   
    double lines[2] = {number1,number2}; //TODO: I accidently wrote double[2]={number1,number2} and this compiled...but what is the use of this? No varibable named array?

    std::cout << "Enter a number to replace the first line of the file by " << std::endl;
    std::cin >> lines[0];

    amountsFile.open(filename,std::ios::out);
    
    if(amountsFile.fail())
    {
        std::cerr <<"\nError!!\nThe file " <<filename 
        << " could not be openend.\nDoes it exist?\n"
        "Perhaps it is being used by another program?\n"
        "Exiting....\n"<< std::endl;
        return -1;
    }
    amountsFile <<  lines[0] <<'\n'<<  lines[1] << '\n';
    amountsFile.close();


     



   
    return 0;
}



