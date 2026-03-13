#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "          EX01 BRAIN TESTER            " << std::endl;
	std::cout << "========================================\n" << std::endl;

	std::cout << "\033[33m========== SUBJECT BASIC TEST =========\033[0m" << std::endl;
	std::cout << "\033[34m[TEST 1] Create and delete via Animal*\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Why this is correct: deleting through Animal* must call Dog/Cat destructors first." << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "Expected dynamic type: Dog -> " << dog->getType() << std::endl;
	std::cout << "Expected dynamic type: Cat -> " << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete cat;
	delete dog;
	std::cout << std::endl;

	std::cout << "\033[33m========== ARRAY OF ANIMALS TEST =========\033[0m" << std::endl;
	std::cout << "\033[34m[TEST 2] Half Dog, half Cat, delete as Animal*\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Why this is correct: every element is deleted as Animal*, proving virtual destructor behavior." << std::endl;
	const int size = 10;
	Animal* animals[size];
	for (int index = 0; index < size; index++)
	{
		if (index < size / 2)
			animals[index] = new Dog();
		else
			animals[index] = new Cat();
	}

	for (int index = 0; index < size; index++)
	{
		std::cout << "animals[" << index << "] type: "
			<< animals[index]->getType() << " -> ";
		animals[index]->makeSound();
	}

	std::cout << "Deleting all elements through Animal*..." << std::endl;
	for (int index = 0; index < size; index++)
		delete animals[index];
	std::cout << std::endl;

	std::cout << "\033[33m========== DEEP COPY TESTS =========\033[0m" << std::endl;
	std::cout << "\033[34m[TEST 3] Dog deep copy (copy constructor)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Goal: copied Dog must own a different Brain and keep independent _ideas." << std::endl;
	Dog originalDog;
	originalDog.setIdea(0, "Chase the ball");
	originalDog.setIdea(1, "Guard the house");
	Dog copiedDog(originalDog);

	std::cout << "Original Dog Brain address: " << originalDog.getBrain() << std::endl;
	std::cout << "Copied Dog Brain address:   " << copiedDog.getBrain() << std::endl;
	std::cout << "Expected: addresses are different (different Brain allocations)." << std::endl;
	std::cout << "copiedDog _ideas[0] before source change: " << copiedDog.getIdea(0) << std::endl;
	std::cout << "copiedDog _ideas[1] before source change: " << copiedDog.getIdea(1) << std::endl;
	originalDog.setIdea(0, "Sleep all day");
	std::cout << "originalDog _ideas[0] after change: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copiedDog _ideas[0] must stay unchanged: " << copiedDog.getIdea(0) << std::endl;
	std::cout << "Why this is correct: if copy were shallow, copiedDog _ideas[0] would also change." << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 4] Cat deep copy (assignment operator)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Goal: assigned Cat must own a different Brain and independent _ideas." << std::endl;
	Cat sourceCat;
	sourceCat.setIdea(0, "Sit on keyboard");
	sourceCat.setIdea(1, "Knock objects down");
	Cat assignedCat;
	assignedCat = sourceCat;

	std::cout << "Source Cat Brain address:   " << sourceCat.getBrain() << std::endl;
	std::cout << "Assigned Cat Brain address: " << assignedCat.getBrain() << std::endl;
	std::cout << "Expected: addresses are different (different Brain allocations)." << std::endl;
	std::cout << "assignedCat _ideas[0] before source change: " << assignedCat.getIdea(0) << std::endl;
	std::cout << "assignedCat _ideas[1] before source change: " << assignedCat.getIdea(1) << std::endl;
	sourceCat.setIdea(0, "Eat and nap");
	std::cout << "sourceCat _ideas[0] after change: " << sourceCat.getIdea(0) << std::endl;
	std::cout << "assignedCat _ideas[0] must stay unchanged: " << assignedCat.getIdea(0) << std::endl;
	std::cout << "Why this is correct: if assignment were shallow, assignedCat _ideas[0] would also change." << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[END] Stack object destructors follow\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}