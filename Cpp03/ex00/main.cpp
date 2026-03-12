#include "ClapTrap.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "       CLAPTRAP TESTING PROGRAM        " << std::endl;
	std::cout << "========================================\n" << std::endl;

	// Test 1: Constructors
	std::cout << "\033[34m[TEST 1] Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ClapTrap	robot1;
	ClapTrap	robot2("R2D2");
	ClapTrap	robot3(robot2);
	ClapTrap	robot4;
	robot4 = robot2;
	std::cout << std::endl;

	// Test 2: Getters
	std::cout << "\033[34m[TEST 2] Getters\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Robot2 Name: " << robot2.getName() << std::endl;
	std::cout << "Robot2 Hit Points: " << robot2.getHitPoints() << std::endl;
	std::cout << "Robot2 Energy Points: " << robot2.getEnergyPoints() << std::endl;
	std::cout << "Robot2 Attack Damage: " << robot2.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// Test 3: Attack
	std::cout << "\033[34m[TEST 3] Attack\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	robot2.attack("Enemy");
	std::cout << "Robot2 Energy Points after attack: " << robot2.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	// Test 4: Take Damage
	std::cout << "\033[34m[TEST 4] Take Damage\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Robot1 takes 3 damage:" << std::endl;
	robot1.takeDamage(3);
	std::cout << std::endl;

	std::cout << "Robot1 takes 5 more damage:" << std::endl;
	robot1.takeDamage(5);
	std::cout << std::endl;

	// Test 5: Be Repaired
	std::cout << "\033[34m[TEST 5] Be Repaired\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Robot1 repairs 3 hit points:" << std::endl;
	robot1.beRepaired(3);
	std::cout << "Robot1 Energy Points after repair: " << robot1.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	// Test 6: Take lethal damage
	std::cout << "\033[34m[TEST 6] Lethal Damage\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Robot1 takes 100 damage (lethal):" << std::endl;
	robot1.takeDamage(100);
	std::cout << std::endl;

	// Test 7: Try to repair when dead (0 hit points)
	std::cout << "\033[34m[TEST 7] Repair when dead\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	robot1.beRepaired(5);
	std::cout << std::endl;

	// Test 8: Try to attack when dead (0 hit points)
	std::cout << "\033[34m[TEST 8] Attack when dead\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	robot1.attack("Target");
	std::cout << std::endl;

	// Test 9: Take damage when already dead
	std::cout << "\033[34m[TEST 9] Take damage when already dead\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	robot1.takeDamage(5);
	std::cout << std::endl;

	// Test 10: Exhaust energy points
	std::cout << "\033[34m[TEST 10] Exhaust Energy Points\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Robot3 attacks until no energy:" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Attack " << i + 1 << ": ";
		robot3.attack("Dummy");
	}
	std::cout << std::endl;

	// Destructors
	std::cout << "\033[34m[END] Destructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}