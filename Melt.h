#ifndef MELT_H
#define MELT_H
#include <stdexcept>

class Melt
{
        friend std::ostream& operator<<(std::ostream&, const Melt&);
        char letter;
    public:
        void setMelt(char l);
        int getValue();
        int operator-(Melt const &m1);
};

void Melt::setMelt(char l)
{
    if(static_cast<int>(l)>=97 && static_cast<int>(l)<=122)
    {
        letter = l;
    }else{
        throw std::invalid_argument("must be lowercase letter");
    }
}

//Overload << operator
std::ostream& operator<<(std::ostream& out, const Melt& melt)
{
    out << melt.letter << " ";
    return out;
}

int Melt::getValue()
{
    return letter - 'a';
}

//Overload - operator
int Melt::operator-(Melt const &m1)
{
    if(m1.letter != letter)
        return 1;
    else
        return 0;
}


#endif // MELT_H
