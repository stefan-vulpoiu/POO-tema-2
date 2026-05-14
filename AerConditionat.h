#pragma once
#include "DispozitivSmart.h"
#include "Interfete.h"

class AerConditionat : public DispozitivSmart, public IReglabil
{
private:
    float temperaturaCurenta;
public:
    AerConditionat(std::string n, float temp = 22.0);

    void regleazaNivel(int valoare) override;

    DispozitivSmart* clone() const override
    {
        return new AerConditionat(*this);
    }

protected:
    void do_afisare(std::ostream& out) const override;
};