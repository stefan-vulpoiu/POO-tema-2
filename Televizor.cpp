#include "Televizor.h"
#include "Exceptii.h"

Televizor::Televizor(std::string n) : DispozitivSmart(n), volum(20), canal(1) {}

void Televizor::regleazaNivel(int procent)
{
    if (procent < 0 || procent > 100)
        throw ValoareInvalidaException("Volumul trebuie sa fie intre 0 si 100!");
    
    volum = procent;
    if (volum > 0)
        porneste();
    else
        opreste();
}

void Televizor::schimbaCanal(int c)
{
    if (c < 1 || c > 999)
        throw ValoareInvalidaException("Canal inexistent!");
    canal = c;
    porneste();
}

void Televizor::do_afisare(std::ostream& out) const
{
    DispozitivSmart::do_afisare(out);
    out << " | Volum: " << volum << " | Canal: " << canal;
}