#include "mainLib.hpp"

int NombreAleatoire(int const MAX, int const MIN)
{
    srand ((unsigned)time(0));
    return rand()%((MAX+1)-MIN)+MIN;
}

bool EstChiffre(std::string const str)
{
    std::string const chiffres {"0123456789"};
    return str.find_first_not_of(chiffres) == std::string::npos;
}