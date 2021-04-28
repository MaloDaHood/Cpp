
#include <cctype>
#include <iostream>

int main()
{
    char const lettre { 'A' };

    std::cout << "Est-ce que " << lettre << " est une minuscule ? " << islower(lettre) << std::endl;
    std::cout << "Est-ce que " << lettre << " est une majuscule ? " << isupper(lettre) << std::endl;
    std::cout << "Est-ce que " << lettre << " est un chiffre ? " << isdigit(lettre) << std::endl;
    
    char const chiffre { '7' };
    
    std::cout << "Est-ce que " << chiffre << " est un chiffre ? " << isdigit(chiffre) << std::endl;
    std::cout << "Est-ce que " << chiffre << " est un signe de ponctuation ? " << ispunct(chiffre) << std::endl;

    return 0;
}