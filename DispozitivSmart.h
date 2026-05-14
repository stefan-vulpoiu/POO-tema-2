#pragma once
#include <string>
#include <iostream>

class DispozitivSmart
{
private:
    //incapsulare; de exemplu se vor folosi porneste()/opreste(), nu bec.estePornit = true;
    std::string nume;
    bool estePornit;
    static int numarTotal; //va tine minte totalul de dispozitive

public:
    DispozitivSmart(std::string n); //constructor
    virtual ~DispozitivSmart(); //destructor virtual

    void afisare(std::ostream& out) const
    {
        do_afisare(out); //apeleaza logica polimorfica
    }

    static int getNumarTotal();

    void porneste();
    void opreste();
    std::string getNume() const;


    friend std::ostream& operator<<(std::ostream& out, const DispozitivSmart& d);

    virtual DispozitivSmart* clone() const = 0;
    //clasele derivate implementeaza clone pentru a returna o copie exacta
    //ajuta la implementarea constructorului de copiere din CasaSmart


//protected si nu private pentru ca vrem ca si clasele derivate BecRgb si Termostat
//sa aiba dreptul sa o vada si sa o suprascrie
protected:
    // NVI:logica virtuala ascunsa, pe care derivatele o vor suprascrie
    virtual void do_afisare(std::ostream& out) const;
};