#include<iostream>
#include "Animal.cpp"
#include "Cat.cpp"
using namespace std;

int main()
{
    Animal a;
    std::cout << a.getNumeAnimal() << std::endl;
    
    Cat cat;

    Animal a2(2, "Chicken");

    Animal a3 = a; //copy constructor
    Animal a4(a); //copy constructor

    a2 = cat; //copy assignment operator

    Animal *a5 = new Cat();
    std::cout << a5->tipAnimal() << std::endl; //functie cu virtual

    a.setNumarPicioare(4);
    std::cout << a.getNumarPicioare() << std::endl;
    std::cout << cat.getNumarPicioare() << " " + cat.getNumeAnimal() << std::endl;
}