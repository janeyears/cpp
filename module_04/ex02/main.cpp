#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    // TEST 1: Cannot instantiate AAnimal directly
    //AAnimal animal;

    // TEST 2: Instantiate Dog and Cat, call makeSound
    Dog dog;
    Cat cat;

    dog.makeSound();
    cat.makeSound();

    // TEST 3: Use pointers to base class
    AAnimal* pDog = new Dog();
    AAnimal* pCat = new Cat();

    pDog->makeSound();
    pCat->makeSound();

    delete pDog;
    delete pCat;

    return 0;
}
