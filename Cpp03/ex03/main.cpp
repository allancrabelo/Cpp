#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "        ALL TRAPS TESTING PROGRAM      " << std::endl;
	std::cout << "========================================\n" << std::endl;

	// ==================== CLAPTRAP TESTS ====================
	std::cout << "\033[33m========== CLAPTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 1] ClapTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ClapTrap clap1("Clappy");
	std::cout << "Clappy stats - HP: " << clap1.getHitPoints() << ", Energy: " << clap1.getEnergyPoints() << ", Damage: " << clap1.getAttackDamage() << std::endl;
	clap1.attack("Target");
	std::cout << std::endl;

	// ==================== SCAVTRAP TESTS ====================
	std::cout << "\033[33m========== SCAVTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 2] ScavTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	ScavTrap scav1("Scavvy");
	std::cout << "Scavvy stats - HP: " << scav1.getHitPoints() << ", Energy: " << scav1.getEnergyPoints() << ", Damage: " << scav1.getAttackDamage() << std::endl;
	std::cout << "(Should be HP: 100, Energy: 50, Damage: 20)" << std::endl;
	scav1.attack("Enemy");
	scav1.guardGate();
	std::cout << std::endl;

	// ==================== FRAGTRAP TESTS ====================
	std::cout << "\033[33m========== FRAGTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 3] FragTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	FragTrap frag1("Fraggy");
	std::cout << "Fraggy stats - HP: " << frag1.getHitPoints() << ", Energy: " << frag1.getEnergyPoints() << ", Damage: " << frag1.getAttackDamage() << std::endl;
	std::cout << "(Should be HP: 100, Energy: 100, Damage: 30)" << std::endl;
	frag1.attack("Victim");
	frag1.highFivesGuys();
	std::cout << std::endl;

	// ==================== DIAMONDTRAP TESTS ====================
	std::cout << "\033[33m========== DIAMONDTRAP TESTS ==========\033[0m\n" << std::endl;

	std::cout << "\033[34m[TEST 4] DiamondTrap Constructors\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DiamondTrap diamond1("Diamondy");
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 5] DiamondTrap Stats\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Diamondy stats - HP: " << diamond1.getHitPoints() << ", Energy: " << diamond1.getEnergyPoints() << ", Damage: " << diamond1.getAttackDamage() << std::endl;
	std::cout << "(Should be HP: 100 (FragTrap), Energy: 50 (ScavTrap), Damage: 30 (FragTrap))" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 6] DiamondTrap whoAmI\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	diamond1.whoAmI();
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 7] DiamondTrap Attack (uses ScavTrap::attack)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	diamond1.attack("Target");
	std::cout << "Energy after attack: " << diamond1.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 8] DiamondTrap inherited functions\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	diamond1.guardGate();
	diamond1.highFivesGuys();
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 9] DiamondTrap takeDamage & beRepaired\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	diamond1.takeDamage(30);
	diamond1.beRepaired(10);
	std::cout << "Diamondy HP after: " << diamond1.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 10] DiamondTrap Copy Constructor\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DiamondTrap diamond2(diamond1);
	std::cout << "Diamond2 (copy) - HP: " << diamond2.getHitPoints() << std::endl;
	diamond2.whoAmI();
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 11] DiamondTrap Assignment Operator\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DiamondTrap diamond3("Temp");
	diamond3 = diamond1;
	std::cout << "Diamond3 (assigned) - HP: " << diamond3.getHitPoints() << std::endl;
	diamond3.whoAmI();
	std::cout << std::endl;

	// Destructors
	std::cout << "\033[34m[END] Destructors (reverse order)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}