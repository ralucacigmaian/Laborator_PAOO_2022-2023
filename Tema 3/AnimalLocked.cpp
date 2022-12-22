#include<iostream>
#include<memory>

class AnimalLocked 
{
    private:
        int numarPicioare = 4;
        bool isLocked = false;

    public:

    AnimalLocked() 
    {
        std::cout << "Constructor fara parametrii" << std::endl;
    }

    AnimalLocked(int numarPicioare)
    {
        this->numarPicioare = numarPicioare;
        std::cout << "Constructor fara parametrii" << std::endl;
    }

    AnimalLocked(const AnimalLocked &al)
    {
        std::cout << "Copy Constructor" << std::endl;
        this->numarPicioare= al.numarPicioare;
        this->isLocked = al.isLocked;
    }

    int printNumarPicioare()
    {
        std::cout << "numarPicioare = " << numarPicioare << std::endl;
        return this->numarPicioare;
    }

    bool printIsLocked()
    {
        std::cout << "isLocked = " << isLocked << std::endl;
        return this->isLocked;
    }

    void setIsLocked(bool isLocked) // Seteaza resursa
    {
        this->isLocked = isLocked;
    }

    ~AnimalLocked()
    {
        std::cout << "Animal Locked a fost sters" << std::endl;
    }

    void askAnimalLocked()  // Functia pentru a verifica daca resursa este blocata de catre alt proces sau nu
    {
        if (this->isLocked) 
            std::cout << "Resursa este blocata!" << std::endl;
        else
            std::cout << "Resursa poate fi folosita!" << std::endl;
    }
};

void lock(AnimalLocked &animal) // Functie pentru a anunta ca resursa este blocata si nu poate fi folosita
{
    std::cout << "Lock resursa!" << std::endl;
    animal.setIsLocked(true);
}

void unlock(AnimalLocked &animal)   // Functie pentru a anunta ca resursa este deblocata si poate fi folosita
{
    std::cout << "Unlock resursa!" << std::endl;
    animal.setIsLocked(false);
}

class LockAnimal    // Clasa pentru a observa starile locked/unlocked
{
    private:
        AnimalLocked &lockPtr;

    public:
    LockAnimal(AnimalLocked &ptr):  // Este locked in constructor
    lockPtr(ptr)
    {
        lock(lockPtr);
    }

    ~LockAnimal()   // Este unlocked in destructor
    {
        unlock(lockPtr);
    }
};