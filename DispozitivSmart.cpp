#include "DispozitivSmart.h"

//initializam atributele direct in lista de initializare a constructorului
int DispozitivSmart::numarTotal = 0;

// Implementarea funcției statice
int DispozitivSmart::getNumarTotal()
{
    return numarTotal;
}

DispozitivSmart::DispozitivSmart(std::string n) : nume(n), estePornit(false)
{
    numarTotal++; //de fiecare data cand se creeaza un dispozitiv (Bec sau Termostat), contorul creste
}

//implementam destructorul pentru a scadea contorul
DispozitivSmart::~DispozitivSmart()
{
    numarTotal--; //cand un obiect este sters, contorul scade
}


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

void DispozitivSmart::do_afisare(std::ostream& out) const
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