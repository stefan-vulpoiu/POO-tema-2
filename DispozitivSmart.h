#pragma once
#include <string>
#include <iostream>

class DispozitivSmart
{
private:
    std::string nume;
    bool estePornit;
    static int numarTotal;

public:
    DispozitivSmart(std::string n); //constructor
    virtual ~DispozitivSmart(); //destructor virtual

    void afisare(std::ostream& os) const
    {
        do_afisare(os); //apeleaza logica polimorfica
    }

    static int getNumarTotal();

    void porneste();
    void opreste();
    std::string getNume() const;


    friend std::ostream& operator<<(std::ostream& os, const DispozitivSmart& d);

    virtual DispozitivSmart* clone() const = 0;

protected:
    // NVI:logica virtuala ascunsa, pe care derivatele o vor suprascrie
    virtual void do_afisare(std::ostream& os) const;
};