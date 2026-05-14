#include "AerConditionat.h"
#include "Exceptii.h"

AerConditionat::AerConditionat(std::string n, float temp)
    : DispozitivSmart(n), temperaturaCurenta(temp) {}

void AerConditionat::regleazaNivel(int valoare)
{
    if (valoare < 10 || valoare > 30) {
        throw ValoareInvalidaException("Aerul conditionat trebuie sa fie intre 10 si 30 de grade!");
    }

    temperaturaCurenta = (float)valoare;
    porneste();
}

void AerConditionat::do_afisare(std::ostream& out) const
{
    DispozitivSmart::do_afisare(out);
    out << " | Temperatura: " << temperaturaCurenta << " grade";
}