#pragma once
#include "DispozitivSmart.h"
#include "Interfete.h"

class Televizor : public DispozitivSmart, public IReglabil
{
private:
    int volum;
    int canal;
public:
    Televizor(std::string n);

    //implementam IReglabil pentru a controla volumul (0-100)
    void regleazaNivel(int procent) override;
    
    //metoda specifica pentru televizor
    void schimbaCanal(int c);

    DispozitivSmart* clone() const override
    {
        return new Televizor(*this);
    }

protected:
    void do_afisare(std::ostream& out) const override;
};