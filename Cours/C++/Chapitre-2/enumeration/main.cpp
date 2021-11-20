#include <iostream>

enum class Jour
{
    Lundi,
    Mardi,
    Mercredi,
    Jeudi,
    Vendredi,
    Samedi,
    Dimanche
};

void Message(Jour const &jourSemaine)
{
    if(jourSemaine==Jour::Samedi||jourSemaine==Jour::Dimanche)
        std::cout << "Bon Week-End !" << std::endl;
    else
        std::cout << "Bon courage !" << std::endl;
}

int main()
{
    Jour const ajrd {Jour::Lundi};
    Message(ajrd);
    return 0;
}