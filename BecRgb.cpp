#include "BecRgb.h"
#include "Exceptii.h"

BecRgb::BecRgb(std::string n) : DispozitivSmart(n), intensitate(0)
{
    //trimit numele mai departe catre constructorul clasei de baza ca sa il initializeze el,
    //apoi setez intensitatea initiala a becului la 0
}

void BecRgb::regleazaNivel(int procent)
{
    //daca procentul este gresit, intrerupem programul si aruncam o exceptie personalizata
    if (procent < 0 || procent > 100)
        throw ValoareInvalidaException("Intensitatea trebuie sa fie intre 0 si 100!");

    intensitate = procent;

    if (intensitate > 0)
        porneste();
    else
        opreste();
}

void BecRgb::do_afisare(std::ostream& out) const
{
    //apelam functionalitatea din clasa parinte pentru a afisa "[Nume] Stare"
    DispozitivSmart::do_afisare(out);
    //si apoi completam specific cu informatiile doar pentru Bec
    out << " | Luminozitate: " << intensitate << "%";
}