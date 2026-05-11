#pragma once
#include "DispozitivSmart.h"
#include "Interfete.h"

//mostenire multipla: BecRgb este un DispozitivSmart si, in acelasi timp,
//implementeaza interfata IReglabil
class BecRgb : public DispozitivSmart, public IReglabil
{
private:
    int intensitate;
public:
    BecRgb(std::string n);

    //'override' obliga compilatorul sa verifice daca suprascriem corect o functie virtuala din clasa parinte
    void regleazaNivel(int procent) override;
    void afisare(std::ostream& os) const override;
};