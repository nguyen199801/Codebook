#ifndef MINT_H
#define MINT_H
#include <stdexcept>
#include <iostream>

class Mint
{
        friend std::ostream& operator<<(std::ostream&, const Mint&);
    private:
        int value;
        int p;
    public:
        int operator-(Mint const &m1);
        void setMint(int v, int modulo);
        int getValue();
};

void Mint::setMint(int v, int modulo)
{
    if(v>=0 && v<=modulo-1 && modulo>=0){
               value = v;
               p = modulo;
    }else{
                throw std::invalid_argument("out of range");
    }
}

int Mint::getValue()
{
    return value;
}

//Overload - operator
int Mint::operator-(Mint const &m1)
{
        return ((value - m1.value%p + p)%p);
}

//Overload << operator
std::ostream& operator<<(std::ostream& out, const Mint &mint)
{
    out << mint.value << " ";
    return out;
}

#endif // MINT_H
