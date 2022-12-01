#include <iostream>
#ifndef ANIMAL_H_
#define ANIMAL_H_
class Animal
{
    private:
        int numarPicioare;
        std::string numeAnimal;
    public:

    Animal() :  numarPicioare(4),
                numeAnimal("Animal Default")
    {
    }

    Animal(int numarPicioare, std::string numeAnimal) : numarPicioare(numarPicioare),
                                                        numeAnimal(numeAnimal)
    {
    }

    Animal(const Animal &a)
    {
        std::cout << "Copy Constructor" << std::endl;
        this->numarPicioare= a.numarPicioare;
        this->numeAnimal = a.numeAnimal;
    }

    Animal& operator=(const Animal &a)
    {
        std::cout << "Copy Assignment Operator" << std::endl;
        this->numarPicioare = a.numarPicioare;
        this->numeAnimal = a.numeAnimal;
        return *this;
    }

    void setNumarPicioare(int numar)
    {
        numarPicioare = numar;
    }

    int getNumarPicioare()
    {
        return numarPicioare;
    }

    void setNumeAnimal(std::string nume)
    {
        numeAnimal = nume;
    }

    std::string getNumeAnimal()
    {
        return numeAnimal;
    }

    virtual std::string tipAnimal()
    {
        return "Tip Animal Default";  
    }

    ~Animal()
    {
        std::cout << "Animalul " + numeAnimal + " a fost sters" << std::endl;
    }
};

#endif