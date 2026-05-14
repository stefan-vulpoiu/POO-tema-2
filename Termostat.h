#pragma once
#include "DispozitivSmart.h"

//termostatul mosteneste toate functionalitatile DispozitivuluiSmart

//spre deosebire de BecRgb, termostatul are o mostenire simpla
//el este un DispozitivSmart, dar nu moștenește interfața IReglabil
class Termostat : public DispozitivSmart
{
private:
    float temperatura;
public:
    Termostat(std::string n);
    void setTemperatura(float t);

    DispozitivSmart* clone() const override
    {
        return new Termostat(*this);
    }

protected:
    void do_afisare(std::ostream& os) const override;
};