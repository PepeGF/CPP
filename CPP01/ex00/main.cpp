#include "Zombie.hpp"

int main()
{
    Zombie *Paco = new Zombie();
    Zombie Manolo = Zombie();

    (void)Manolo;
    delete (Paco);

    return (0);
}