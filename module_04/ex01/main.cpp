#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define ARRAY_SIZE 4

void testDeepCopy()
{
    std::cout << "Testing deep copy..." << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want food.");
    dog1.getBrain()->setIdea(1, "I want to play.");

    Dog dog2 = dog1; // Copy constructor

    dog2.getBrain()->setIdea(0, "I want sleep.");
    dog2.getBrain()->setIdea(1, "I want walk.");

    std::cout << "Dog1 Ideas:" << std::endl;
    std::cout << dog1.getBrain()->getIdea(0) << std::endl; // Should print "I want food."
    std::cout << dog1.getBrain()->getIdea(1) << std::endl; // Should print "I want to play."

    std::cout << "Dog2 Ideas:" << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl; // Should print "I want sleep."
    std::cout << dog2.getBrain()->getIdea(1) << std::endl; // Should print "I want walk."
}

void testArrayCreationAndDeletion()
{
    std::cout << "Testing array creation and deletion..." << std::endl;
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < ARRAY_SIZE; ++i)
        delete animals[i]; // Should call Dog or Cat destructors properly
}

int main()
{
    testDeepCopy();
    testArrayCreationAndDeletion();

    return 0;
}
