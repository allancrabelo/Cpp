#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "      ANIMAL POLYMORPHISM TESTER       " << std::endl;
	std::cout << "========================================\n" << std::endl;

	std::cout << "\033[33m========== SUBJECT MANDATORY TEST =========\033[0m\n" << std::endl;
	std::cout << "\033[34m[TEST 1] Animal pointers to Dog/Cat\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "Expected here: Dog" << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << "Expected here: Cat" << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << "Expected here: Cat sound (Meow Meow!)" << std::endl;
	cat->makeSound();
	std::cout << "Expected here: Dog sound (Woof Woof!)" << std::endl;
	dog->makeSound();
	std::cout << "Expected here: generic Animal sound" << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 2] Deleting through Animal*\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	delete cat;
	delete dog;
	delete meta;
	std::cout << std::endl;

	std::cout << "\033[33m========== EXTRA POLYMORPHISM TESTS =========\033[0m\n" << std::endl;
	std::cout << "\033[34m[TEST 3] Polymorphic array (Animal*)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	for (int index = 0; index < 4; index++)
	{
		std::cout << "animals[" << index << "] type: "
			<< animals[index]->getType() << " -> ";
		std::cout << "(expected: sound from the type above) ";
		animals[index]->makeSound();
	}
	for (int index = 0; index < 4; index++)
		delete animals[index];
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 4] Copy constructor and assignment\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	Cat assignedCat;
	Cat sourceCat;
	assignedCat = sourceCat;
	std::cout << "copiedDog type: " << copiedDog.getType() << std::endl;
	std::cout << "assignedCat type: " << assignedCat.getType() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m========== WRONG ANIMAL TESTS =========\033[0m\n" << std::endl;
	std::cout << "\033[34m[TEST 5] WrongAnimal pointer to WrongCat\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "Expected here: default" << std::endl;
	std::cout << wrongMeta->getType() << std::endl;
	std::cout << "Expected here: WrongCat" << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	std::cout << "Expected here: WrongAnimal noises." << std::endl;
	wrongMeta->makeSound();
	std::cout << "Here (intentionally WRONG), expected: WrongAnimal noises." << std::endl;
	std::cout << "If it were virtual, this would print WrongCat noises." << std::endl;
	wrongCat->makeSound();
	std::cout << "Correct for the wrong exercise: call through WrongAnimal* does NOT use override." << std::endl;
	delete wrongCat;
	delete wrongMeta;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 6] Direct WrongCat call\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	WrongCat directWrongCat;
	std::cout << "Expected here: WrongCat noises." << std::endl;
	directWrongCat.makeSound();
	std::cout << "Correct: direct call on WrongCat object uses WrongCat method." << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[END] Remaining stack destructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}