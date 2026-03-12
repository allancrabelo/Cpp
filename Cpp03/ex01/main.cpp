#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "       CLAPTRAP & SCAVTRAP TESTS       " << std::endl;
	std::cout << "========================================\n" << std::endl;

	// ==================== CLAPTRAP TESTS ====================
	std::cout << "\033[33m========== CLAPTRAP TESTS ==========\033[0m\n" << std::endl;

	// Test 1: ClapTrap Constructors
	std::cout << "\033[34m[TEST 1] ClapTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ClapTrap clap1;
	ClapTrap clap2("Clappy");
	std::cout << std::endl;

	// Test 2: ClapTrap Actions
	std::cout << "\033[34m[TEST 2] ClapTrap Actions\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Clappy stats - HP: " << clap2.getHitPoints() << ", Energy: " << clap2.getEnergyPoints() << ", Damage: " << clap2.getAttackDamage() << std::endl;
	clap2.attack("Target");
	clap2.takeDamage(5);
	clap2.beRepaired(3);
	std::cout << std::endl;

	// ==================== SCAVTRAP TESTS ====================
	std::cout << "\033[33m========== SCAVTRAP TESTS ==========\033[0m\n" << std::endl;

	// Test 3: ScavTrap Constructors
	std::cout << "\033[34m[TEST 3] ScavTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ScavTrap scav1;
	ScavTrap scav2("Scavvy");
	std::cout << std::endl;

	// Test 4: ScavTrap Stats (should be different from ClapTrap)
	std::cout << "\033[34m[TEST 4] ScavTrap Stats\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Scavvy stats - HP: " << scav2.getHitPoints() << ", Energy: " << scav2.getEnergyPoints() << ", Damage: " << scav2.getAttackDamage() << std::endl;
	std::cout << "(Should be HP: 100, Energy: 50, Damage: 20)" << std::endl;
	std::cout << std::endl;

	// Test 5: ScavTrap Attack (different message from ClapTrap)
	std::cout << "\033[34m[TEST 5] ScavTrap Attack\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	scav2.attack("Enemy");
	std::cout << "Scavvy Energy after attack: " << scav2.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	// Test 6: ScavTrap guardGate
	std::cout << "\033[34m[TEST 6] ScavTrap guardGate\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	scav2.guardGate();
	scav2.guardGate(); // Should say already in gate keeper mode
	std::cout << std::endl;

	// Test 7: ScavTrap takes damage and repairs
	std::cout << "\033[34m[TEST 7] ScavTrap takeDamage & beRepaired\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	scav2.takeDamage(30);
	scav2.beRepaired(10);
	std::cout << "Scavvy HP after: " << scav2.getHitPoints() << std::endl;
	std::cout << std::endl;

	// Test 8: ScavTrap Copy Constructor
	std::cout << "\033[34m[TEST 8] ScavTrap Copy Constructor\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ScavTrap scav3(scav2);
	std::cout << "Scav3 (copy of Scavvy) - HP: " << scav3.getHitPoints() << ", Energy: " << scav3.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	// Test 9: ScavTrap Assignment Operator
	std::cout << "\033[34m[TEST 9] ScavTrap Assignment Operator\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	scav1 = scav2;
	std::cout << "Scav1 (assigned from Scavvy) - HP: " << scav1.getHitPoints() << std::endl;
	std::cout << std::endl;

	// Test 10: Exhaust ScavTrap energy
	std::cout << "\033[34m[TEST 10] Exhaust ScavTrap Energy\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ScavTrap scav4("Energizer");
	std::cout << "Attacking 52 times (energy = 50):" << std::endl;
	for (int i = 0; i < 52; i++)
	{
		scav4.attack("Dummy");
	}
	std::cout << std::endl;

	// Destructors
	std::cout << "\033[34m[END] Destructors (reverse order)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}