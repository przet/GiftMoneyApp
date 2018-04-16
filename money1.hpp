#ifndef MONEY__H
#define MONEY__H

#include "item.hpp"
#include <stdexcept>
class Money1 
{
    private:
        double m_amount;
        
    public:
        Money1(const double amt): m_amount(amt) {}
        void setAmount(double amt)
        { m_amount = amt;}
        double getAmount()
        { return m_amount; }
        void deductItem(Item &item)
        { m_amount -= item.getPrice(); }
};

class Money2
{
    private:
        double m_amount;
        Money1 *m_money1_ptr;
    public:
        Money2(const double amt, Money1 *money1_ptr) : m_amount(amt), m_money1_ptr(money1_ptr)
        {

            if (m_money1_ptr == nullptr)
                throw std::runtime_error ("null pointer: money1_ptr");
            m_amount = -m_money1_ptr->getAmount();


        }
        double getAmount()
        { return m_amount; }
};
    

#endif
        
        
