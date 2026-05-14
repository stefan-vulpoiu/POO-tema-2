#pragma once
#include "DispozitivSmart.h"
#include "Interfete.h"

//mostenire multipla: BecRgb este un DispozitivSmart si, in acelasi timp,
//implementeaza interfata IReglabil
class BecRgb : public DispozitivSmart, public IReglabil //mosteneste DispozitivSmart; implementeaza IReglabil
{
private:
    int intensitate;
public:
    BecRgb(std::string n);

    //'override' obliga compilatorul sa verifice daca suprascriem corect o functie virtuala din clasa parinte
    void regleazaNivel(int procent) override;

    DispozitivSmart* clone() const override //constructor de copiere
    {
        return new BecRgb(*this); //foloseste constructorul de copiere default
    }

protected:
    void do_afisare(std::ostream& os) const override;
};