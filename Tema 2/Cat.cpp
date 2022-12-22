#include<iostream>
#include"Animal.cpp"

class Cat : public Animal
{
    private:
    std::string culoareAnimal;

    public:
    Cat() : Animal(4, "Tigrut"), culoareAnimal("Negru")
    {
    }

    Cat(int numarPicioare, std::string numeAnimal, std::string culoareAnimal) : Animal(numarPicioare, numeAnimal), culoareAnimal(culoareAnimal)
    {
    }

    //Tema 2 -> Item 12

    Cat& operator=(const Cat &c)
    {
        if (this == &c)
        {
            std::cout << "Aceeasi referinta" << std::endl;
            return *this;
        }
        Animal::operator=(c);   //daca nu se pune asta, se va actualiza doar culoarea animalului
        this->culoareAnimal = c.culoareAnimal;
        return *this;
    }

    std::string tipAnimal() 
    {
        return "Cat"; 
    }

    std::string getCuloareAnimal()
    {
        return culoareAnimal;
    }

    ~Cat()
    {
        std::cout << "Animalul Cat a fost sters" << std::endl;
    }
};