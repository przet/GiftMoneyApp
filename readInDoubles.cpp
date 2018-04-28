#include <fstream>
#include <string>
#include <iostream>

//B: stands for "behaviour". Where a new behaviour extends an old behavior, that old behavior will
//be deleted from here

int main()
{
    std::string mystr;
    std::cout << "What is your name? " << std::endl;
    getline(std::cin, mystr);
    std::cout << "Hello " << mystr << std::endl;

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
    

    //B:From input read in a value (double) such that:
    //if prev val - new val > 0, we replace the first line with result(prev val - new val)
    //else the first line becomes 0, and the second line is result(prev val - new val + second line) add as prev - new is <0 in this case
    //

    double lines[2] = {number1,number2}; //TODO: I accidently wrote double[2]={number1,number2} and this compiled...but what is the use of this? No varibable named array?

    double inputVal;
    std::cout << "Enter a number to replace the first line of the file by " << std::endl;
    std::cin >> inputVal;
    
    amountsFile.open(filename,std::ios::out);
    
    if(amountsFile.fail())
    {
        std::cerr <<"\nError!!\nThe file " <<filename 
        << " could not be openend.\nDoes it exist?\n"
        "Perhaps it is being used by another program?\n"
        "Exiting....\n"<< std::endl;
        return -1;
    }
    double newFirstLine = lines[0] - inputVal;
    if (newFirstLine >= 0) 
        amountsFile <<  newFirstLine <<'\n'<<  lines[1] << '\n';
    else amountsFile << 0 << '\n' << (lines[1] + newFirstLine) << '\n';
    
    amountsFile.close();
    //B: Read in a description and append to bottom of the file

    std::cout << "\n\n Please Enter a description : " << std::endl;
    
    std::string description;
    getline(std::cin,description);
    std::cout << description << std::endl; 
    amountsFile.open(filename,std::ios::app);
    amountsFile << '\n' << description << '\n';
    amountsFile.close();
     



   

    std::cout << "Exiting..." << std::endl;
    return 0;
}



