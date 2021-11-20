#include <iostream>
#include "limits"
#include "infos.hpp"

template <typename T>
T Input()
{
    T input {};
    while(!(std::cin >> input))
    {
        std::cout << "Entree invalide. Recommence." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

void Infos::GetInfos()
{
    std::cout << "Quel est votre prenom ?" << std::endl;
    prenom=Input<std::string>();
    std::cout << "Quel est votre nom ?" << std::endl;
    nom=Input<std::string>();
    std::cout << "Quel est votre age ?" << std::endl;
    age=Input<int>();
}

void Infos::ShowInfos()
{
    std::cout << "*****************************" << std::endl;
    std::cout << "Prenom : " << prenom << std::endl;
    std::cout << "Nom : " << nom << std::endl;
    std::cout << "Age : " << age << std::endl;
}