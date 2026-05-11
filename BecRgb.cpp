#include "BecRgb.h"
#include "Exceptii.h"

BecRgb::BecRgb(std::string n) : DispozitivSmart(n), intensitate(0) {}

void BecRgb::regleazaNivel(int procent)
{
    //daca procentul este gresit, intrerupem programul si aruncam o exceptie personalizata
    if (procent < 0 || procent > 100)
        throw ValoareInvalidaException("Intensitatea trebuie sa fie intre 0 si 100!");

    intensitate = procent;
    estePornit = (intensitate > 0);
}

void BecRgb::afisare(std::ostream& out) const
{
    //apelam functionalitatea din clasa parinte pentru a afisa "[Nume] Stare"
    DispozitivSmart::afisare(out);
    //si apoi completam specific cu informatiile doar pentru Bec
    out << " | Luminozitate: " << intensitate << "%";
}