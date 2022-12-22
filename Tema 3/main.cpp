#include<iostream>
#include "Animal.cpp"
#include "AnimalLocked.cpp"
#include <memory>
using namespace std;

// factory function care creaza obiectul, incapsularea procesului de a crea obiecte
Animal* createAnimalInstance()
{
    return (new Animal);
}

int main()
{
    // Tema 3 -> Item 13

    // Cazul 1 -> auto_ptr

    std::cout<<"auto_ptr"<<std::endl;
    {
        // auto_ptr nu se mai foloseste, fiind deprecated => va exista un warning
        // In schimb, vom folosi unique_ptr
        // a1 pointeaza catre obiectul returnat de createAnimalInstance
        // a2 pointeaza acum catre obiect, iar a1 devine NULL => are loc schimbare de ownership
        std::auto_ptr<Animal> a1(createAnimalInstance());
        a1->printNumeAnimal();
        std::auto_ptr<Animal> a2(a1);
        a2->printNumeAnimal();
        // a1->printNumeAnimal(); => SEGMENTATION FAULT deoarece a1 este NULL
    }

    std::cout<<std::endl;

    // Cazul 2 -> unique_ptr

    std::cout<<"unique_ptr"<<std::endl;
    {  
        // La unique_ptr nu se poate copia, in acest caz se foloseste functia move pentru schimbare de ownership
        std::unique_ptr<Animal> a3(createAnimalInstance());
        a3->printNumeAnimal();
        std::unique_ptr<Animal> a4 = move(a3);
        a4->printNumeAnimal();
        // a3->printNumeAnimal(); => SEGMENTATION FAULT
    }

    std::cout<<std::endl;

    std::cout<<"shared_ptr"<<std::endl;
    {
        // Folosim use_count() pentru a afisa numarul de instante
        // Cu shared_ptr putem copia, iar un counter se va incrementa pentru a ne spune numarul de copii ale obiectului
        // Obiectul se va distruge cand counter-ul este 0
        // Totodata, ambii pointeri ponteaza catre acelasi obiect
        // Cu functia move am realizat din nou schimbarea de ownership
        std::shared_ptr<Animal> a1(createAnimalInstance());
        a1->printNumeAnimal();
        std::cout << "Count = " << a1.use_count() << std::endl;
        std::shared_ptr<Animal> a2(a1);
        std::cout << "Count = " << a1.use_count() << std::endl;
        a2->printNumeAnimal();
        a1->printNumeAnimal();
        std::shared_ptr<Animal> a3 = move(a1);
        std::cout << "Count = " << a1.use_count() << std::endl; // Nu mai este owner-ul resursei => Count = 0
        std::cout << "Count = " << a3.use_count() << std::endl; // A devenit owner-ul resursei => Count = 2
        a3->changeNumeAnimal("Tigrut");
        a3->printNumeAnimal();
        a2->printNumeAnimal();
        // a1->printNumeAnimal(); => SEGMENTATION FAULT
    }

    std::cout<<std::endl;

    // Tema 3 -> Item 14

    // Intial locked este false

    AnimalLocked al(2);
    LockAnimal *lockedAnimal = new LockAnimal(al);  // locked -> true => blocheaza resursa
    al.askAnimalLocked();
    delete lockedAnimal;    // locked -> false => deblocheaza resursa
    al.askAnimalLocked();
    std::cout << "Functioneaza!" << std::endl;
}