#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "   CLAPTRAP, SCAVTRAP & FRAGTRAP TESTS " << std::endl;
	std::cout << "========================================\n" << std::endl;

	// ==================== CLAPTRAP TESTS ====================
	std::cout << "\033[33m========== CLAPTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 1] ClapTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ClapTrap clap1;
	ClapTrap clap2("Clappy");
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 2] ClapTrap Actions\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Clappy stats - HP: " << clap2.getHitPoints() << ", Energy: " << clap2.getEnergyPoints() << ", Damage: " << clap2.getAttackDamage() << std::endl;
	clap2.attack("Target");
	clap2.takeDamage(5);
	clap2.beRepaired(3);
	std::cout << std::endl;

	// ==================== SCAVTRAP TESTS ====================
	std::cout << "\033[33m========== SCAVTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 3] ScavTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ScavTrap scav1;
	ScavTrap scav2("Scavvy");
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 4] ScavTrap Stats\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Scavvy stats - HP: " << scav2.getHitPoints() << ", Energy: " << scav2.getEnergyPoints() << ", Damage: " << scav2.getAttackDamage() << std::endl;
	std::cout << "(Should be HP: 100, Energy: 50, Damage: 20)" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 5] ScavTrap Attack & guardGate\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	scav2.attack("Enemy");
	scav2.guardGate();
	scav2.guardGate();
	std::cout << std::endl;

	// ==================== FRAGTRAP TESTS ====================
	std::cout << "\033[33m========== FRAGTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 6] FragTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	FragTrap frag1;
	FragTrap frag2("Fraggy");
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 7] FragTrap Stats\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Fraggy stats - HP: " << frag2.getHitPoints() << ", Energy: " << frag2.getEnergyPoints() << ", Damage: " << frag2.getAttackDamage() << std::endl;
	std::cout << "(Should be HP: 100, Energy: 100, Damage: 30)" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 8] FragTrap Attack\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	frag2.attack("Victim");
	std::cout << "Fraggy Energy after attack: " << frag2.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 9] FragTrap highFivesGuys\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	frag2.highFivesGuys();
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 10] FragTrap takeDamage & beRepaired\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	frag2.takeDamage(50);
	frag2.beRepaired(20);
	std::cout << "Fraggy HP after: " << frag2.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 11] FragTrap Copy Constructor\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	FragTrap frag3(frag2);
	std::cout << "Frag3 (copy of Fraggy) - HP: " << frag3.getHitPoints() << ", Energy: " << frag3.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 12] FragTrap Assignment Operator\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	frag1 = frag2;
	std::cout << "Frag1 (assigned from Fraggy) - HP: " << frag1.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 13] Kill FragTrap and try highFive\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	frag2.takeDamage(200);
	frag2.highFivesGuys();
	std::cout << std::endl;

	// Destructors
	std::cout << "\033[34m[END] Destructors (reverse order)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}