#pragma once
#include <exception>
#include <string>

//baza ierarhiei de exceptii
class SmartHomeException : public std::exception
{
private:
    std::string mesaj;
public:
    SmartHomeException(const std::string& m) : mesaj(m) //parametrul m este rezultatul lui throw
    {
        //gol pentru ca am initializat deja pe linia anterioara
        //am creat variabila mesaj si am pus valoarea parametrului m
    }

    //suprascriem metoda standard din std::exception
    //noexcept garanteaza ca aceasta funcție nu va arunca, la randul ei, o alta exceptie
    const char* what() const noexcept override
    {
        return mesaj.c_str();
        //extrage textul din .c_str() si il transforma in const char*, asa cum cere functia what()
    }
};

//exceptie pentru valori in afara limitelor (ex: 150% luminozitate)
//Mosteneste clasa SmartHomeException; adauga mesajul Valoare Invalida - la inceputul mesajelor
class ValoareInvalidaException : public SmartHomeException
{
public:
    ValoareInvalidaException(const std::string& m) : SmartHomeException("Valoare Invalida - " + m) {}
};

//exceptie pentru cazul in care un dispozitiv nu este gasit dupa nume
//Mosteneste clasa SmartHomeException; adauga mesajul pentru inexistenta numelui
class DispozitivInexistentException : public SmartHomeException
{
public:
    DispozitivInexistentException(const std::string& nume)
        : SmartHomeException("Dispozitivul '" + nume + "' nu exista in baza de date!") {}
};