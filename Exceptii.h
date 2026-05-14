#pragma once
#include <exception>
#include <string>

//baza ierarhiei de exceptii
class SmartHomeException : public std::exception
{
private:
    std::string mesaj;
public:
    SmartHomeException(const std::string& m) : mesaj(m) {}

    //suprascriem metoda standard din std::exception
    //noexcept garanteaza ca aceasta funcție nu va arunca, la randul ei, o alta exceptie
    const char* what() const noexcept override
    {
        return mesaj.c_str();
    }
};

//exceptie pentru valori in afara limitelor (ex: 150% luminozitate)
class ValoareInvalidaException : public SmartHomeException
{
public:
    ValoareInvalidaException(const std::string& m) : SmartHomeException("Valoare Invalida - " + m) {}
};

//exceptie pentru cazul in care un dispozitiv nu este gasit dupa nume
class DispozitivInexistentException : public SmartHomeException
{
public:
    DispozitivInexistentException(const std::string& nume)
        : SmartHomeException("Dispozitivul '" + nume + "' nu exista in baza de date!") {}
};