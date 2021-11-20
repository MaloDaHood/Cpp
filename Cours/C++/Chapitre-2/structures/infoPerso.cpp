#include <iostream>
#include <fstream>
#include <limits>
#include <string>

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

int main()
{
    std::ofstream fichier {"Prenom.Nom.csv"};
    std::cout << "Nom ? ";
    std::string nom {Input<std::string>()};
    std::cout << "Prenom ? ";
    std::string prenom {Input<std::string>()};
    std::cout << "Sexe ? ";
    std::string sexe {Input<std::string>()};
    std::cout << "Age ? ";
    int age {Input<int>()};
    fichier << nom << ',' << prenom << ',' << sexe << ',' << age;
    std::cout << "Ces donnees seront enregistrees dans le fichier " << nom << '.' << prenom << ".csv" << std::endl;
    std::ofstream fichierPerso {nom+'.'+prenom+".csv"};
    fichierPerso << nom << ',' << prenom << ',' << sexe << ',' << age;
    return 0;
}