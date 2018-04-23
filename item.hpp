#ifndef ITEM__H
#define ITEM__H
#include <string>
class Item
{
    private:
        double price;
        std::string description;

    public:
        void setPrice(double p)
        { price = p; }
        double getPrice()
        { return price;}
        void setDescription(std::string &s)
        {description = s;}
        std::string getDescription()
        { return description; }
};

#endif
