#pragma once

//interfata pentru dispozitivele care au un nivel reglabil (0-100)
class IReglabil
{
public:
    virtual void regleazaNivel(int procent) = 0;
    virtual ~IReglabil() = default;
};