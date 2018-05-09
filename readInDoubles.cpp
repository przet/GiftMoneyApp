#include <fstream>
#include <string>
#include <iostream>
#include <algorithm> //std::find

//B: stands for "behaviour". Where a new behaviour extends an old behavior, that old behavior will
//be deleted from here

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
    std::cout << "\n\nGift Money Amount One: "<< number1 << std::endl;
    std::cout << "Gift Money Amount One: " << number2 << "\n" << std::endl;
    amountsFile.close();

    //B:From input read in a value (double) such that:
    //if prev val - new val > 0, we replace the first line with result(prev val - new val)
    //else the first line becomes 0, and the second line is result(prev val - new val + second line) add as prev - new is <0 in this case
    //

    double lines[2] = {number1,number2}; //TODO: I accidently wrote double[2]={number1,number2} and this compiled...but what is the use of this? No varibable named array?

    double inputVal;
    std::cout << "Enter the price of the item you wish to deduct.\n"
        "DON'T include any symbols like $"<< std::endl;
    std::cin >> inputVal; 
    //TODO: guard against non numerical input. Could check if first char is NOT in ascii set containing numbers
    
    amountsFile.open(filename,std::ios::in | std::ios::out);//This prevents opening in out only
                                                            //, which overwrites everything in the file!
                                                            // Overrite removes any previous descriptions we
                                                            // do below - the money remains because we are first
                                                            // (above) reading it in, then storing it/writing it back!
                                                            //TODO Why bitwise ?
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
    
    //B: Read in a description  and append to bottom of the file
    std::cout << "Enter the item's description... When done, enter 'end' on a new line " << std::endl;
    std::string description;
    amountsFile.open(filename,std::ios::app);

    while(getline(std::cin,description) && description != "end")
        amountsFile << description<<"    $" <<inputVal <<'\n';

    amountsFile.close();
    std::cout << "Exiting..." << std::endl;
    return 0;
}



