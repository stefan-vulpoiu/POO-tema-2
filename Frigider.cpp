#include "Frigider.h"
#include "Exceptii.h"

Frigider::Frigider(std::string n, float temp) : DispozitivSmart(n), temperaturaCurenta(temp)
{
    this->porneste();
}

void Frigider::regleazaNivel(int valoare)
{
    if (valoare < 1 || valoare > 7) {
        throw ValoareInvalidaException("Temperatura frigiderului trebuie sa fie intre 1 si 7 grade!");
    }

    temperaturaCurenta = (float)valoare;
    std::cout << "-> Frigiderul '" << getNume() << "' a fost setat la " << temperaturaCurenta << " grade\n";
}

void Frigider::do_afisare(std::ostream& out) const
{
    DispozitivSmart::do_afisare(out);
    out << " | Temperatura: " << temperaturaCurenta << " grade";
}