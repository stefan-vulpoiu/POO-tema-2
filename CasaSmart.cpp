#include "CasaSmart.h"
#include "Interfete.h"
#include "Termostat.h"
#include "Exceptii.h"

CasaSmart& CasaSmart::operator+=(DispozitivSmart* d)
{
    dispozitive.push_back(d);
    return *this;
}

void CasaSmart::afiseazaToate() const
{
    std::cout << "\n--- STATUS CASA SMART ---\n";
    if (dispozitive.empty())
        std::cout << "(Niciun dispozitiv instalat)\n";
    for (auto d : dispozitive)
        std::cout << *d << "\n"; //aici se apeleaza polimorfic metoda 'afisare()' a fiecarui obiect derivat
}

void CasaSmart::activeazaModSeara()
{
    std::cout << "\n>>> Activare Mod Seara...\n";
    for (auto d : dispozitive)
    {
        //dynamic_cast: Intrebam sistemul la rulare daca pointerul curent de baza
        //implementeaza, de fapt, interfata IReglabil. Daca da, metoda returneaza pointerul valid
        IReglabil* r = dynamic_cast<IReglabil*>(d);
        if (r) r->regleazaNivel(20);

        //intrebam daca pointerul reprezinta de fapt un Termostat pentru a aplica o setare specifica
        Termostat* t = dynamic_cast<Termostat*>(d);
        if (t) t->setTemperatura(22.0);
    }
}

void CasaSmart::regleazaDispozitiv(const std::string& nume, int valoare)
{
    for (auto d : dispozitive)
    {
        if (d->getNume() == nume)
        {
            IReglabil* r = dynamic_cast<IReglabil*>(d);
            if (r)
            {
                r->regleazaNivel(valoare);
                return;
            }

            Termostat* t = dynamic_cast<Termostat*>(d);
            if (t)
            {
                t->setTemperatura((float)valoare);
                return;
            }

            //daca gasim dispozitivul dar tipul lui nu permite reglaje prin 'int'
            throw SmartHomeException("Acest dispozitiv nu poate fi reglat!");
        }
    }

    //daca am iesit din bucla for() si nu am dat return, inseamna ca nu s-a gasit in vector
    throw DispozitivInexistentException(nume);
}

void CasaSmart::stergeDispozitiv(const std::string& nume)
{

    //folosim 'auto it' pentru un iterator, obligatoriu atunci cand stergem elemente cu .erase()
    for (auto it = dispozitive.begin(); it != dispozitive.end(); ++it)
    {

        // '*it' este pointerul in sine (ex: DispozitivSmart*); deci apelam functiile prin ->
        if ((*it)->getNume() == nume)
        {
            delete *it; //eliberam memoria
            dispozitive.erase(it); //scoatem referinta din vector
            std::cout << "-> Dispozitiv sters cu succes.\n";
            return;
        }
    }
    throw DispozitivInexistentException(nume);
}

CasaSmart::~CasaSmart()
{
    for (auto d : dispozitive)
        delete d;
}