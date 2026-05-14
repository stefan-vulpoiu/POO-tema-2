#pragma once
#include <vector>
#include "DispozitivSmart.h"

class CasaSmart
{
private:
    // Compozitie si Polimorfism: Vectorul stocheaza POINTERI la clasa de baza (*)
    // Astfel, in aceeasi colectie putem pune si obiecte de tip BecRgb si de tip Termostat
    std::vector<DispozitivSmart*> dispozitive;
public:

    CasaSmart() = default;
    //constructor de copiere (Deep Copy)
    CasaSmart(const CasaSmart& other);

    //functia swap prietena
    friend void swap(CasaSmart& first, CasaSmart& second) noexcept;

    //supraincarcarea operatorului= (Copy-and-Swap)
    CasaSmart& operator=(CasaSmart other);

    //supraincarcarea operatorului '+=', pentru a putea adauga dispozitive (casa += bec_nou)
    CasaSmart& operator+=(DispozitivSmart* d);

    void afiseazaToate() const;
    void activeazaModSeara();
    void regleazaDispozitiv(const std::string& nume, int valoare);
    void stergeDispozitiv(const std::string& nume);
    ~CasaSmart(); //destructor
};