#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const char *green = "\033[32m";
	const char *red = "\033[31m";
	const char *yellow = "\033[33m";
	const char *blue = "\033[34m";
	const char *reset = "\033[0m";

	std::cout << "========================================" << std::endl;
	std::cout << "      EX02 ABSTRACT ANIMAL TESTER      " << std::endl;
	std::cout << "========================================\n" << std::endl;
	std::cout << yellow << "[ABSTRACT RULE] " << reset
		<< "Animal cannot be instantiated because makeSound() is pure virtual." << std::endl;
	std::cout << green << "[OK] " << reset
		<< "Only Dog/Cat are created in this main." << std::endl;
	std::cout << std::endl;

	std::cout << yellow << "========== SUBJECT BASIC TEST =========" << reset << std::endl;
	std::cout << blue << "[TEST 1] Create and delete via Animal*" << reset << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << yellow << "[WHY] " << reset
		<< "Deleting through Animal* must call derived destructors first." << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "Expected dynamic type: Dog -> " << dog->getType() << std::endl;
	std::cout << "Expected dynamic type: Cat -> " << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete cat;
	delete dog;
	std::cout << green << "[PASS] " << reset
		<< "Program reaches here after deleting derived objects as Animal*." << std::endl;
	std::cout << std::endl;

	std::cout << yellow << "========== ARRAY OF ANIMALS TEST =========" << reset << std::endl;
	std::cout << blue << "[TEST 2] Half Dog, half Cat, delete as Animal*" << reset << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << yellow << "[WHY] " << reset
		<< "Every element is deleted as Animal*, proving virtual destructor behavior." << std::endl;
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
	std::cout << green << "[PASS] " << reset
		<< "Array deleted via base pointers without leaks/crash." << std::endl;
	std::cout << std::endl;

	std::cout << yellow << "========== DEEP COPY TESTS =========" << reset << std::endl;
	std::cout << blue << "[TEST 3] Dog deep copy (copy constructor)" << reset << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << yellow << "[GOAL] " << reset
		<< "copied Dog must own a different Brain and independent _ideas." << std::endl;
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
	bool dogAddrOk = (originalDog.getBrain() != copiedDog.getBrain());
	bool dogIdeaOk = (copiedDog.getIdea(0) == "Chase the ball");
	if (dogAddrOk && dogIdeaOk)
		std::cout << green << "[PASS] " << reset << "Deep copy confirmed for Dog (_ideas are independent)." << std::endl;
	else
		std::cout << red << "[FAIL] " << reset << "Shallow-copy symptom detected in Dog." << std::endl;
	std::cout << yellow << "[WHY] " << reset
		<< "If copy were shallow, copiedDog _ideas[0] would change with originalDog." << std::endl;
	std::cout << std::endl;

	std::cout << blue << "[TEST 4] Cat deep copy (assignment operator)" << reset << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << yellow << "[GOAL] " << reset
		<< "assigned Cat must own a different Brain and independent _ideas." << std::endl;
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
	bool catAddrOk = (sourceCat.getBrain() != assignedCat.getBrain());
	bool catIdeaOk = (assignedCat.getIdea(0) == "Sit on keyboard");
	if (catAddrOk && catIdeaOk)
		std::cout << green << "[PASS] " << reset << "Deep copy confirmed for Cat assignment (_ideas are independent)." << std::endl;
	else
		std::cout << red << "[FAIL] " << reset << "Shallow-copy symptom detected in Cat assignment." << std::endl;
	std::cout << yellow << "[WHY] " << reset
		<< "If assignment were shallow, assignedCat _ideas[0] would change with sourceCat." << std::endl;
	std::cout << std::endl;

	std::cout << blue << "[END] Stack object destructors follow" << reset << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}