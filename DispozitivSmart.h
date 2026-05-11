#pragma once
#include <string>
#include <iostream>

class DispozitivSmart
{
private:
    std::string nume;
    bool estePornit;

public:
    DispozitivSmart(std::string n); //constructor
    virtual ~DispozitivSmart() = default; //destructor virtual

    void porneste();
    void opreste();
    std::string getNume() const;

    virtual void afisare(std::ostream& os) const; //virtual: permite suprascrierea in clasele derivate
    friend std::ostream& operator<<(std::ostream& os, const DispozitivSmart& d);
};