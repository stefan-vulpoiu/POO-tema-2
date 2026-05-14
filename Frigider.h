#pragma once
#include "DispozitivSmart.h"
#include "Interfete.h"

class Frigider : public DispozitivSmart, public IReglabil
{
private:
    float temperaturaCurenta;
public:
    Frigider(std::string n, float temp = 4.0);

    void regleazaNivel(int valoare) override;

    DispozitivSmart* clone() const override
    {
        return new Frigider(*this);
    }

protected:
    void do_afisare(std::ostream& out) const override;
};