#include <iostream>
#include <cstdlib>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    Weapon Sword("Sword");
    HumanA Kayle("Kayle", Sword);

    Kayle.attack();
    Sword.setType("Divine Judgment");
    Kayle.attack();

    std::cout << std::endl;

    Weapon Chains("Chains");
    HumanB Morgana("Morgana");

    Morgana.attack();
    Morgana.weaponSetter(Chains);
    Morgana.attack();

    Chains.setType("Soul Shackles");
    Morgana.attack();

    return (EXIT_SUCCESS);
}
