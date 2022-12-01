#include<iostream>
#include"Animal.cpp"

class Cat : public Animal
{
    public:
    Cat() : Animal(4, "Tigrut")
    {
    }

    std::string tipAnimal() 
    {
        return "Cat"; 
    }

    ~Cat()
    {
        std::cout << "Animalul Cat a fost sters" << std::endl;
    }
};