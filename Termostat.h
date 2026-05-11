#pragma once
#include "DispozitivSmart.h"

//termostatul mosteneste toate functionalitatile DispozitivuluiSmart
class Termostat : public DispozitivSmart
{
private:
    float temperatura;
public:
    Termostat(std::string n);
    void setTemperatura(float t);
    void afisare(std::ostream& out) const override;
};