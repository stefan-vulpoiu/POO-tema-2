#include "Termostat.h"
#include "Exceptii.h"

//initializam termostatul cu o temperatura prestabilita (20.0)
Termostat::Termostat(std::string n) : DispozitivSmart(n), temperatura(20.0) {}

void Termostat::setTemperatura(float t)
{
    //mecanism de siguranta prin tratarea exceptiilor
    if (t < 10.0 || t > 35.0)
        throw ValoareInvalidaException("Temperatura trebuie sa fie intre 10 si 35 grade!");
    temperatura = t;
    estePornit = true;
}

void Termostat::afisare(std::ostream& out) const
{
    DispozitivSmart::afisare(out);
    out << " | Temp: " << temperatura << "C";
}