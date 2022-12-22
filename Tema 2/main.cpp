#include<iostream>
#include "Animal.cpp"
#include "Cat.cpp"
using namespace std;

int main()
{
    //Tema 2 -> Item 10
    Animal a6(2, "Rex");
    Animal a7(4, "Blinky");
    Animal a8(6, "Piki");
    a6 += a7 += a8;
    std::cout << a6.getNumarPicioare() << std::endl;

    //Tema 2 -> Item 11
    Animal a9;
    a9 = a9;

    //Tema 2 -> Item 12
    Cat cat1(4, "Puf", "Maro");
    Cat cat2(3, "Whitey", "Alb");
    cat1 = cat2;
    std::cout << cat1.getNumarPicioare() << " " + cat1.getNumeAnimal() << std::endl;
    std::cout << cat1.getCuloareAnimal() << std::endl;
}