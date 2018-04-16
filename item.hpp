#ifndef ITEM__H
#define ITEM__H
class Item
{
    private:
        double price;
    public:
        void setPrice(double p)
        { price = p; }
        double getPrice()
        { return price;}
};

#endif
