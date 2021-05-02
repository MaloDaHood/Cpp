#include "mainLib.hpp"

void ErreurEntree(int const MAX, int const MIN)
{
    if(MAX-MIN==1)
        std::cout << "Vous devez rentrer soit " << MIN << ", soit " << MAX << "." << std::endl;
    else
        std::cout << "Vous devez rentrer un chiffre entre " << MIN << " et " << MAX << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

std::string Majuscule(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string Minuscule(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool EstLettre(std::string const str)
{
    std::string const lettres {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};
    return str.find_first_not_of(lettres) == std::string::npos;
}