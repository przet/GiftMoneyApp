#include<iostream>
#include<string>

int main()
{
    std::cout << "Please enter a number: " << std::endl;
    double inputNumber;
    std::cin >> inputNumber;

    std::cout << "Please enter a description... When done, enter 'end' on a new line " << std::endl;
    std::string description;
    while(getline(std::cin,description) && description != "end") //TODO why does getline need to be in a while? If I just write
                                                                // std::cin >> description, it will be fine (for one input non-newlined, and of course
                                                                // whitespace will not be read in this case
    std::cout << "\n\n" << description << "\n" << std::endl;
    return 0;
}
