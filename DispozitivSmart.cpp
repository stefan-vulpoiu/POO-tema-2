#include "DispozitivSmart.h"

//initializam atributele direct in lista de initializare a constructorului
DispozitivSmart::DispozitivSmart(std::string n) : nume(n), estePornit(false) {}

void DispozitivSmart::porneste()
{
    estePornit = true;
}
void DispozitivSmart::opreste()
{
    estePornit = false;
}
std::string DispozitivSmart::getNume() const
{
    return nume;
}

void DispozitivSmart::afisare(std::ostream& out) const
{
    out << "[" << nume << "] Stare: " << (estePornit ? "ON" : "OFF");
}

std::ostream& operator<<(std::ostream& out, const DispozitivSmart& d)
{
    //la executie, se va apela metoda 'afisare' potrivita tipului real al
    //obiectului trimis (BecRgb sau Termostat), nu doar cea de baza
    d.afisare(out);
    return out;
}