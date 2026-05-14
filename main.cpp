#include <iostream>
#include <string>
#include "CasaSmart.h"
#include "BecRgb.h"
#include "Termostat.h"
#include "Exceptii.h"
#include "Televizor.h"

using namespace std;

void afiseazaMeniu()
{
    cout << "\n--- MENIU SMART HOME ---\n";
    cout << "status  - Vezi toate dispozitivele\n";
    cout << "seara   - Mod Seara (automat)\n";
    cout << "seteaza - Modifica un dispozitiv\n";
    cout << "sterge  - Elimina un dispozitiv\n";
    cout << "exit    - Iesire\n";
    cout << "------------------------\n";
}

int main()
{
    CasaSmart casa;

    //inițializam casa cu cateva dispozitive
    casa += new BecRgb("LuminaSufragerie");
    casa += new BecRgb("LuminaDormitor");
    casa += new Termostat("TermostatCentral");
    casa += new Televizor("TV_Living");

    string comanda;
    while (true)
    {
        afiseazaMeniu();
        cout << "Comanda: ";
        cin >> comanda;

        if (comanda == "exit")
            break;

        try {
            if (comanda == "status") {
                casa.afiseazaToate();
            }
            else if (comanda == "seara") {
                casa.activeazaModSeara();
            }
            else if (comanda == "seteaza") {
                string nume;
                int valoare;
                cout << "Nume dispozitiv: "; cin >> nume;
                cout << "Valoare noua: "; cin >> valoare;
                casa.regleazaDispozitiv(nume, valoare);
            }
            else if (comanda == "sterge") {
                string nume;
                cout << "Nume de sters: "; cin >> nume;
                casa.stergeDispozitiv(nume);
            }
            else {
                cout << "Comanda invalida! Te rog sa incerci din nou.\n";
            }
        }
        //excepțiile noastre personalizate (ValoareInvalida, DispozitivInexistent)
        catch (const SmartHomeException& e) {
            cerr << "\a[EROARE SMART HOME]: " << e.what() << endl;
        }
        //erori standard de C++
        catch (const exception& e)
        {
            cerr << "\a[EROARE SISTEM]: " << e.what() << endl;
        }
        catch (...)
        {
            cerr << "\a[EROARE]: A aparut o problema necunoscuta!" << endl;
        }
    }

    return 0;
}


/*
Ghid de testare la rulare:

- status: afiseaza starea tuturor dispozitivelor (demonstreaza NVI si Polimorfismul)

- seteaza: modifica un dispozitiv:
    * Nume: LuminaDormitor | Valoare: 0-100
    * Nume: LuminaSufragerie | Valoare: 0-100 (exemplu: 80 -> Becul se aprinde la 80%)
    * Nume: TermostatCentral | Valoare: 10-35 (exemplu: 100 -> Prinde exceptia custom (100 > 35 grade)
                                               si afiseaza eroarea fara sa dea crash)
    * Nume: TV_Living | Valoare: 0-99

- seara: scade automat toate becurile la 20%, seteaza termostatul la 22C (demonstreaza dynamic_cast)
         si inchide televizorul

- sterge: elimina definitiv un dispozitiv:
    * Nume: LuminaDormitor | Sterge dispozitivul din vector si elibereaza memoria
    * Nume: LuminaSufragerie | Sterge dispozitivul din vector si elibereaza memoria
    * Nume: TermostatCentral | Sterge dispozitivul din vector si elibereaza memoria
    * Nume: TV_Living | Sterge dispozitivul din vector si elibereaza memoria
    * Nume: Invalid | (exemplu: Televizor -> Prinde exceptia custom de dispozitiv inexistent
                       si afiseaza eroarea fara sa dea crash)

- exit: inchide programul curat (apeleaza destructorul virtual pentru a preveni memory leaks)

*/